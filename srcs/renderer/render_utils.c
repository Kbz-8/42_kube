/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:32:05 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/08 10:21:15 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <stdbool.h>
#include <stdint.h>
#include <mlx.h>

void draw_line(t_renderer *renderer, t_vec2 v0, t_vec2 v1, int color)
{
	float tmp;
	bool steep = false;
	if (fabsf(v0.x - v1.x) < fabsf(v0.y - v1.y))
	{
		tmp = v0.x; v0.x = v0.y; v0.y = tmp;
		tmp = v1.x; v1.x = v1.y; v1.y = tmp;
		steep = true;
	}
	if (v0.x > v1.x)
	{
		tmp = v0.x; v0.x = v1.x; v1.x = tmp;
		tmp = v0.y; v0.y = v1.y; v1.y = tmp;
	}
	int dx = v1.x - v0.x;
	int dy = v1.y - v0.y;
	float derror = fabsf(dy / (float)dx);
	float error = 0;
	int y = v0.y;
	for(int x = v0.x; x <= v1.x; x++)
	{
		if (steep)
			mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, y, x, color);
		else
			mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, x, y, color);
		error += derror;
		if (error > 0.5f)
		{
			y += (v1.y > v0.y ? 1 : -1);
			error -= 1.0f;
		}
	}
}

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

void	draw_rect(t_renderer *renderer, t_vec2 pos, t_vec2 dims, int color)
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;

	x = 0;
	mlx = renderer->plat->mlx;
	win = renderer->plat->win;
	while (x < dims.x)
	{
		y = 0;
		while (y < dims.y)
		{
			mlx_pixel_put(mlx, win, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}

int	get_color(t_color color)
{
	uint8_t	res[4];

	res[3] = 0xFF;
	res[2] = color.r;
	res[1] = color.g;
	res[0] = color.b;
	return (*(int *)res);
}
