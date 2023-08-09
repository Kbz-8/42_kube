/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:31:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 13:05:19 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <renderer.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <utils.h>
#include <dda.h>

static void	process_walls(t_ray *ray, t_dda *dda)
{
	ray->line_h = (int)(CUBE_SIZE * HEIGHT) / ray->distance;
	ray->texy_off = 0;
	ray->tex_step = TEXTURE_SIZE / (float)ray->line_h;
	if (ray->line_h > HEIGHT)
	{
		ray->texy_off = (ray->line_h - HEIGHT) / 2;
		ray->line_h = HEIGHT;
	}
	ray->line_pos.x = ray->i;
	ray->line_pos.y = (HEIGHT / 2) - (ray->line_h / 2);
	ray->line_off = ray->line_pos.y;
	ray->tex.y = ray->texy_off * ray->tex_step;
	if (dda->distance.x > dda->distance.y)
	{
		ray->tex.x = (int)ray->pos.x % TEXTURE_SIZE;
		if (ray->ang > M_PI)
			ray->tex.x = TEXTURE_SIZE - 1 - ray->tex.x;
	}
	else
	{
		ray->tex.x = (int)ray->pos.y % CUBE_SIZE;
		if (ray->ang > M_PI / 2 && ray->ang < 3 * M_PI / 2)
			ray->tex.x = TEXTURE_SIZE - 1 - ray->tex.x;
	}
}

static void	draw_walls(t_renderer *r, t_dda *dda, t_ray *ray, t_player *player)
{
	void	*mlx;
	void	*win;
	uint8_t	color[4];
	int		y;
	int		texture_id;

	y = 0;
	mlx = r->plat->mlx;
	win = r->plat->win;
	texture_id = get_texture_id(player, ray);
	while (y < ray->line_h)
	{
		*(int *)color = mlx_get_image_pixel(mlx, r->tex[texture_id].img, \
				(int)ray->tex.x, (int)ray->tex.y);
		depth_lightning(color, ray, dda);
		reverse_array(color, 3);
		mlx_pixel_put(mlx, win, ray->line_pos.x, ray->line_pos.y + y, \
				*(int *)color);
		ray->tex.y += ray->tex_step;
		y++;
	}
}

static void	draw_floor_ceiling(t_renderer* renderer, t_ray *ray)
{
	void	*mlx[2];
	t_world	*w;
	uint8_t	color[4];
	float	j[2];
	int		i;

	j[0] = 1.0f;
	i = ray->line_off + ray->line_h;
	mlx[0] = renderer->plat->mlx;
	mlx[1] = renderer->plat->win;
	w = renderer->world;
	while (i < HEIGHT)
	{
		j[0] += 0.1f;
		j[1] = 1.0f - (1.0f - (((float)i / HEIGHT) - 0.5f)) * \
			   			(1.0f - (((float)i / HEIGHT) - 0.5f));
		color[2] = (uint8_t)((w->floor.r - (w->floor.r / j[0])) * j[1]);
		color[1] = (uint8_t)((w->floor.g - (w->floor.g / j[0])) * j[1]);
		color[0] = (uint8_t)((w->floor.b - (w->floor.b / j[0])) * j[1]);
		mlx_pixel_put(mlx[0], mlx[1], ray->i, i, *(int *)color);
		mlx_pixel_put(mlx[0], mlx[1], ray->i, HEIGHT - i, \
				get_color(w->ceiling));
		i++;
	}
}

void	render(t_renderer *renderer, t_player *player)
{
	t_ray	ray;
	t_dda	dda;

	ray.ang = player->angle - DEG_TO_RAD * (FOV / 2);
	ray.ang = fix_ang(ray.ang);
	ray.i = WIDTH;
	while (ray.i > -1)
	{
		dda_algorithm(renderer, player, &ray, &dda);
		ray.distance *= cos(fix_ang(player->angle - ray.ang));
		process_walls(&ray, &dda);
		draw_walls(renderer, &dda, &ray, player);
		draw_floor_ceiling(renderer, &ray);
		ray.ang += DEG_TO_RAD / (WIDTH / FOV);
		ray.ang = fix_ang(ray.ang);
		ray.i--;
	}
}

