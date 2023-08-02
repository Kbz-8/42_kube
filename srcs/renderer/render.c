/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:31:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 19:15:40 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <renderer.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <utils.h>

void	draw_vert_line(t_renderer *renderer, t_vec2 pos, int h, int color)
{
	while (pos.y < h)
	{
		mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, pos.x, pos.y, \
						color);
		pos.y++;
	}
}

static void drawRays2D(t_renderer *renderer, t_player *player)
{
	int dof;
	float r;
	float ra, disV, disH;
	t_vec2 rv;
	t_vec2 v;
	t_vec2 m;
	t_vec2 o;

	ra = fix_ang(player->angle + 30);

	for(r = 0; r < 60; r++)
	{
		dof = 0;
		disV = 100000;
		float Tan = tan(deg_to_rad(ra));
		if(cos(deg_to_rad(ra)) > 0.001)
		{
			rv.x = (((int)player->pos.x >> 6) << 6) + 64;
			rv.y = (player->pos.x - rv.x) * Tan + player->pos.y;
			o.x = 64;
			o.y =- o.x * Tan;
		}
		else if(cos(deg_to_rad(ra)) < -0.001)
		{
			rv.x = (((int)player->pos.x >> 6) << 6) - 0.0001;
			rv.y = (player->pos.x - rv.x) * Tan + player->pos.y;
			o.x = -64;
			o.y = -o.x * Tan;
		}
		else
		{
			rv.x = player->pos.x;
			rv.y = player->pos.y;
			dof = 8;
		}

		while(dof < 8)
		{
			m.x = (int)(rv.x) >> 6;
			m.y = (int)(rv.y) >> 6;
			if(m.x >= 0 && m.x < 8 && m.y >= 0 && m.y < 8 && renderer->world->map[(int)m.y][(int)m.x] == 1)
			{
				dof = 8;
				disV = cos(deg_to_rad(ra)) * (rv.x - player->pos.x) - sin(deg_to_rad(ra)) * (rv.y - player->pos.y);
			}
			else
			{ 
				rv.x += o.x;
				rv.y += o.y;
				dof += 1;
			}
		}
		v.x = rv.x;
		v.y = rv.y;

		dof = 0;
		disH = 100000;
		Tan = 1.0 / Tan;
		if(sin(deg_to_rad(ra)) > 0.001)
		{
			rv.y = (((int)player->pos.y >> 6) << 6) - 0.0001;
			rv.x =(player->pos.y - rv.y) * Tan + player->pos.x;
			o.y = -64;
			o.x = -o.y * Tan;
		}
		else if(sin(deg_to_rad(ra)) < -0.001)
		{
			rv.y = (((int)player->pos.y >> 6) << 6) + 64;
			rv.x = (player->pos.y - rv.y) * Tan + player->pos.x;
			o.y = 64;
			o.x = -o.y * Tan;
		}
		else
		{
			rv.x = player->pos.x;
			rv.y = player->pos.y;
			dof = 8;
		}

		while(dof < 8)
		{
			m.x = (int)(rv.x) >> 6;
			m.y = (int)(rv.y) >> 6;
			if(m.x >= 0 && m.x < 8 && m.y >= 0 && m.y < 8 && renderer->world->map[(int)m.y][(int)m.x] == 1)
			{
				dof = 8;
				disH = cos(deg_to_rad(ra)) * (rv.x - player->pos.x) - sin(deg_to_rad(ra)) * (rv.y - player->pos.y);
			}
			else
			{
				rv.x += o.x;
				rv.y += o.y;
				dof += 1;
			}
		}

		int color = 0x000000FF;
		if(disV < disH)
		{
			rv.x = v.x;
			rv.y = v.y;
			disH = disV;
			color = 0x00000088;
		}

		int ca = fix_ang(player->angle - ra);
		disH = disH * cos(deg_to_rad(ca));
		int lineH = (64 * 720) / (disH);
		if(lineH > 720)
			lineH = 720;
		int lineOff = 360 - (lineH >> 1);

		for(int i = 0; i < 8; i++)
		{
			t_vec2 origin = { r * 8 + i, lineOff};
			draw_vert_line(renderer, origin, lineH, color);
		}

		ra = fix_ang(ra - 1);
	}
}

void	render(t_renderer *renderer, t_player *player)
{
	mlx_clear_window(renderer->plat->mlx, renderer->plat->win);
	drawRays2D(renderer, player);
}

