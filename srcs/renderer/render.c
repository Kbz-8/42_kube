/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:31:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/07 03:46:05 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <renderer.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <utils.h>

#ifdef BONUS
static const bool minimap = true;
#else
static const bool minimap = false;
#endif

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

static void	draw_vert_line(t_renderer *renderer, t_vec2 pos, int h, int color)
{
	int	i;

	i = pos.y;
	while (i < pos.y + h)
	{
		mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, pos.x, i, \
						color);
		i++;
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
	t_vec2 s;

	s.x = renderer->world->map_x_size;
	s.y = renderer->world->map_y_size;
	ra = fix_ang(player->angle + 30);

	for(r = 0; r < 156; r++)
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
			o.x = -(64);
			o.y = -o.x * Tan;
		}
		else
		{
			rv.x = player->pos.x;
			rv.y = player->pos.y;
			dof = s.x;
		}

		while(dof < s.x)
		{
			m.x = (int)(rv.x) >> 6;
			m.y = (int)(rv.y) >> 6;
			if(m.x >= 0 && m.x < s.x && m.y >= 0 && m.y < s.y && renderer->world->map[(int)m.y][(int)m.x] == '1')
			{
				dof = s.x;
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
			o.y = -(64);
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
			dof = s.y;
		}

		while(dof < s.y)
		{
			m.x = (int)(rv.x) >> 6;
			m.y = (int)(rv.y) >> 6;
			if(m.x >= 0 && m.x < s.x && m.y >= 0 && m.y < s.y && renderer->world->map[(int)m.y][(int)m.x] == '1')
			{
				dof = s.y;
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
		int lineH = ((64) * 720) / (disH);
		if(lineH > 720)
			lineH = 720;
		int lineOff = 360 - (lineH >> 1);

		for(int i = 0; i < 8; i++)
		{
			t_vec2 origin = { r * 8 + i, lineOff};
			draw_vert_line(renderer, origin, lineH, color);
		}

		ra = fix_ang(ra - 0.5f);
	}
}

void	render(t_renderer *renderer, t_player *player)
{
	mlx_clear_window(renderer->plat->mlx, renderer->plat->win);
	int xo, yo;
	int color;
	drawRays2D(renderer, player);
	if (minimap)
	{
		for(int y = 0; y < renderer->world->map_y_size; y++)
		{
			for(int x = 0; x < renderer->world->map_x_size; x++)
			{
				if(renderer->world->map[x][y] == '1')
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
		for(int i = player->pos.x / 7; i < player->pos.x / 7 + 4; i++)
		{
			for(int j = player->pos.y / 7; j < player->pos.y / 7 + 4; j++)
				mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, i, j, 0x00FF0000);
		}
	}
}

