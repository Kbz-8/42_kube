/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:32:05 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 13:06:29 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <stdbool.h>
#include <stdint.h>
#include <mlx.h>
#include <dda.h>
#include <utils.h>

void	draw_vert_line(t_renderer *renderer, t_vec2 pos, int h, int color)
{
	void	*mlx;
	void	*win;
	int		i;

	i = pos.y;
	mlx = renderer->plat->mlx;
	win = renderer->plat->win;
	while (i < pos.y + h)
	{
		mlx_pixel_put(mlx, win, pos.x, i, color);
		i++;
	}
}

int	get_color(t_color color)
{
	uint8_t	res[4];

	res[3] = 0xFF;
	res[2] = (uint8_t)color.r;
	res[1] = (uint8_t)color.g;
	res[0] = (uint8_t)color.b;
	return (*(int *)res);
}

int	get_texture_id(t_player *player, t_ray *ray)
{
	if (ft_fabs(roundf(ray->pos.y) - ray->pos.y) <= 0.002f)
	{
		if (ray->pos.y < player->pos.y)
			return (1);
		return (0);
	}
	else if (ft_fabs(roundf(ray->pos.x) - ray->pos.x) <= 0.002f)
	{
		if (ray->pos.x < player->pos.x)
			return (3);
		return (2);
	}
	return (0);
}

// [1 - (1 - (color / 255))²] correction function to ensure smooth shading
void	depth_lightning(uint8_t color[4], t_ray *ray, t_dda *dda)
{
	int		dst;
	float	cor;

	dst = ray->distance * 0.2f;
	if (dda->distance.x < dda->distance.y)
		dst += 35;
	if (dst > 235)
		dst = 235;
	cor = 1 - (1 - (float)color[2] / 0x100) * (1 - (float)color[2] / 0x100);
	color[2] = (uint8_t)((color[2] - dst * cor > 0) * (color[2] - dst * cor));
	cor = 1 - (1 - (float)color[1] / 0x100) * (1 - (float)color[1] / 0x100);
	color[1] = (uint8_t)((color[1] - dst * cor > 0) * (color[1] - dst * cor));
	cor = 1 - (1 - (float)color[0] / 0x100) * (1 - (float)color[0] / 0x100);
	color[0] = (uint8_t)((color[0] - dst * cor > 0) * (color[0] - dst * cor));
}
