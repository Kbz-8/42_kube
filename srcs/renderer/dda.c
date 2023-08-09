/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:32:43 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 10:43:56 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <dda.h>
#include <stdbool.h>

static void	setup_vert_dda(t_renderer *r, t_player *p, t_dda *dda, t_ray *ray)
{
	dda->distance.x = 100000;
	dda->i = r->world->map_x_size;
	dda->tan = tan(ray->ang);
	dda->run = true;
	if (cos(ray->ang) < -0.001)
	{
		ray->pos.x = (((int)p->pos.x >> 6) << 6) - 0.001;
		ray->pos.y = (p->pos.x - ray->pos.x) * dda->tan + p->pos.y;
		ray->offset.x = -CUBE_SIZE;
		ray->offset.y = -ray->offset.x * dda->tan;
	}
	else if (cos(ray->ang) > 0.001)
	{
		ray->pos.x = (((int)p->pos.x >> 6) << 6) + CUBE_SIZE;
		ray->pos.y = (p->pos.x - ray->pos.x) * dda->tan + p->pos.y;
		ray->offset.x = CUBE_SIZE;
		ray->offset.y = -ray->offset.x * dda->tan;
	}
	else
	{
		ray->pos.x = p->pos.x;
		ray->pos.y = p->pos.y;
		dda->run = false;
	}
}

static void	setup_hori_dda(t_renderer *r, t_player *p, t_dda *dda, t_ray *ray)
{
	dda->distance.y = 100000;
	dda->i = r->world->map_y_size;
	dda->tan = 1 / tan(ray->ang);
	dda->run = true;
	if (sin(ray->ang) > 0.001)
	{
		ray->pos.y = (((int)p->pos.y >> 6) << 6) - 0.001;
		ray->pos.x = (p->pos.y - ray->pos.y) * dda->tan + p->pos.x;
		ray->offset.y = -CUBE_SIZE;
		ray->offset.x = -ray->offset.y * dda->tan;
	}
	else if (sin(ray->ang) < -0.001)
	{
		ray->pos.y = (((int)p->pos.y >> 6) << 6) + CUBE_SIZE;
		ray->pos.x = (p->pos.y - ray->pos.y) * dda->tan + p->pos.x;
		ray->offset.y = CUBE_SIZE;
		ray->offset.x = -ray->offset.y * dda->tan;
	}
	else
	{
		ray->pos.x = p->pos.x;
		ray->pos.y = p->pos.y;
		dda->run = false;
	}
}

static void	dda_loop(t_renderer *r, t_dda *dda, t_ray *ray, t_player *p)
{
	size_t	w;
	size_t	h;

	w = r->world->map_x_size;
	h = r->world->map_y_size;
	while (dda->run && dda->i)
	{
		dda->map.x = (int)(ray->pos.x) >> 6;
		dda->map.y = (int)(ray->pos.y) >> 6;
		if (dda->map.x >= 0 && dda->map.x < w && dda->map.y >= 0 && \
			dda->map.y < h && \
			r->world->map[(int)dda->map.y][(int)dda->map.x] == '1')
		{
			if (dda->horizontal)
				dda->distance.y = dist(p->pos, ray->pos);
			else
				dda->distance.x = dist(p->pos, ray->pos);
			dda->i = 0;
		}
		else
		{
			vec2_add(&ray->pos, ray->offset);
			dda->i--;
		}
	}
}

void	dda_algorithm(t_renderer *r, t_player *player, t_ray *ray, t_dda *dda)
{
	setup_vert_dda(r, player, dda, ray);
	dda->horizontal = false;
	dda_loop(r, dda, ray, player);
	dda->vert.x = ray->pos.x;
	dda->vert.y = ray->pos.y;
	setup_hori_dda(r, player, dda, ray);
	dda->horizontal = true;
	dda_loop(r, dda, ray, player);
	dda->hori.x = ray->pos.x;
	dda->hori.y = ray->pos.y;
	if (dda->distance.x < dda->distance.y)
	{
		ray->pos.x = ft_fabs(dda->vert.x);
		ray->pos.y = ft_fabs(dda->vert.y);
		ray->distance = dda->distance.x;
	}
	else
	{
		ray->pos.x = ft_fabs(dda->hori.x);
		ray->pos.y = ft_fabs(dda->hori.y);
		ray->distance = dda->distance.y;
	}
}
