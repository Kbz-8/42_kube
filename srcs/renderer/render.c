/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:31:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/08 11:15:46 by maldavid         ###   ########.fr       */
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

#ifdef BONUS
static const bool minimap = true;
#else
static const bool minimap = false;
#endif

static void	process_walls(t_ray *ray)
{
	ray->lineh = (int)(CUBE_SIZE * HEIGHT) / ray->distance;
	if (ray->lineh > HEIGHT)
		ray->lineh = HEIGHT;
	ray->line_pos.x = ray->i;
	ray->line_pos.y = (HEIGHT / 2) - (ray->lineh / 2);
	ray->lineoff = (HEIGHT / 2) - (ray->lineh / 2);
}

static void	draw_floor_ceiling(t_renderer* renderer, t_ray *ray)
{
	void	*mlx;
	void	*win;
	int		i;
	t_color	ao;

	ft_memset(&ao, 0, sizeof(t_color));
	i = ray->lineoff + ray->lineh;
	mlx = renderer->plat->mlx;
	win = renderer->plat->win;
	while (i < HEIGHT)
	{
		mlx_pixel_put(mlx, win, ray->i, i, get_color(ao));
		mlx_pixel_put(mlx, win, ray->i, HEIGHT - i, get_color(renderer->world->ceiling));
		i++;
		ao.r = renderer->world->floor.r / (i - (ray->lineoff + ray->lineh));
		ao.g = renderer->world->floor.g / (i - (ray->lineoff + ray->lineh));
		ao.b = renderer->world->floor.b / (i - (ray->lineoff + ray->lineh));
	}
}

static void	draw_walls(t_renderer *renderer, t_dda *dda, t_ray *ray)
{
	int8_t	color[4];
	int		dst;

	dst = ray->distance * 0.5f;
	if (dda->distance.x < dda->distance.y)
		dst += 25;
	if (dst > 200)
		dst = 200;
	color[3] = 0xFF;
	color[2] = 255 - dst;
	color[1] = 255 - dst;
	color[0] = 255 - dst;
	draw_vert_line(renderer, ray->line_pos, ray->lineh, *(int *)color);
}

static void	render_walls(t_renderer *renderer, t_player *player)
{
	t_ray	ray;
	t_dda	dda;

	ray.ang = player->angle - DR * (FOV / 2);
	ray.ang = fix_ang(ray.ang);
	ray.i = 0;
	while (ray.i < WIDTH)
	{
		dda_algorithm(renderer, player, &ray, &dda);
		ray.coang = fix_ang(player->angle - ray.ang);
		ray.distance *= cos(ray.coang);
		process_walls(&ray);
		draw_walls(renderer, &dda, &ray);
		draw_floor_ceiling(renderer, &ray);
		ray.ang += DR / (WIDTH / FOV);
		ray.ang = fix_ang(ray.ang);
		ray.i++;
	}
}

void	render(t_renderer *renderer, t_player *player)
{
	int xo, yo;
	t_vec2	player_size;
	int		color;

	mlx_clear_window(renderer->plat->mlx, renderer->plat->win);
	render_walls(renderer, player);
	if (minimap)
	{
		for(size_t y = 0; y < renderer->world->map_y_size; y++)
		{
			for(size_t x = 0; x < renderer->world->map_x_size; x++)
			{
				if(renderer->world->map[y][x] == '1')
					color = 0x00444444;
				else
					color = 0x00FFFFFF;
				xo = x * 10;
				yo = y * 10;
				for(int i = xo; i < 10 + xo; i++)
				{
					for(int j = yo; j < 10 + yo; j++)
						mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, j, i, color);
				}
			}
		}
		player_size.x = 4;
		player_size.y = 4;
		draw_rect(renderer, vec2_div_n_copy(player->pos, 7), player_size, 0x00FF0000);
	}
}

