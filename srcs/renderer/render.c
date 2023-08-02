/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:31:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 15:03:40 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <renderer.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void	render(t_renderer *renderer, t_player *player)
{
	mlx_clear_window(renderer->plat->mlx, renderer->plat->win);

	int xo, yo;
	int color;
	for(int y = 0; y < 8; y++)
	{
		for(int x = 0; x < 8; x++)
		{
			if(renderer->world->map[x][y] == 1)
				color = 0x00444444;
			else
				color = 0x00FFFFFF;
			xo = x * 64;
			yo = y * 64;
			for(int i = xo + 1; i < 64 + xo - 1; i++)
			{
				for(int j = yo + 1; j < 64 + yo - 1; j++)
					mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, j, i, color);
			}
		} 
	} 

	t_vec2 v = vec2_add_copy(player->pos, vec2_mul_n_copy(player->dir, 20));
	draw_line(renderer, player->pos, v, 0x00FF0000);
}

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
