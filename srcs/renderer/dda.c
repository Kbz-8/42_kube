/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:32:43 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/08 10:18:26 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <dda.h>
#include <stdbool.h>

static void	setup_vertical_dda(t_renderer *renderer, t_player *player, t_dda *dda, t_ray *ray)
{
	dda->distance.x = 100000;
	dda->ddai = renderer->world->map_x_size + 1;
	dda->tan = tan(ray->ang);
	dda->dodda = true;
	if (cos(ray->ang) < -0.001)
	{
		ray->pos.x = (((int)player->pos.x >> 6) << 6) - 0.001;
		ray->pos.y = (player->pos.x - ray->pos.x) * dda->tan + player->pos.y;
		ray->offset.x = -64;
		ray->offset.y = -ray->offset.x * dda->tan;
	}
	else if (cos(ray->ang) > 0.001)
	{
		ray->pos.x = (((int)player->pos.x >> 6) << 6) + 64;
		ray->pos.y = (player->pos.x - ray->pos.x) * dda->tan + player->pos.y;
		ray->offset.x = 64;
		ray->offset.y = -ray->offset.x * dda->tan;
	}
	else
	{
		ray->pos.x = player->pos.x;
		ray->pos.y = player->pos.y;
		dda->dodda = false;
	}
}

static void	setup_horizontal_dda(t_renderer *renderer, t_player *player, t_dda *dda, t_ray *ray)
{
	dda->distance.y = 100000;
	dda->ddai = renderer->world->map_y_size + 1;
	dda->tan = 1 / tan(ray->ang);
	dda->dodda = true;
	if (sin(ray->ang) > 0.001)
	{
		ray->pos.y = (((int)player->pos.y >> 6) << 6) - 0.001;
		ray->pos.x = (player->pos.y - ray->pos.y) * dda->tan + player->pos.x;
		ray->offset.y = -64;
		ray->offset.x = -ray->offset.y * dda->tan;
	}
	else if (sin(ray->ang) < -0.001)
	{
		ray->pos.y = (((int)player->pos.y >> 6) << 6) + 64;
		ray->pos.x = (player->pos.y - ray->pos.y) * dda->tan + player->pos.x;
		ray->offset.y = 64;
		ray->offset.x = -ray->offset.y * dda->tan;
	}
	else
	{
		ray->pos.x = player->pos.x;
		ray->pos.y = player->pos.y;
		dda->dodda = false;
	}
}

static void	dda_loop(t_renderer *r, bool hor, t_dda *dda, t_ray *ray, t_player *p)
{
	size_t	w;
	size_t	h;

	w = r->world->map_x_size;
	h = r->world->map_y_size;
	while (dda->dodda && dda->ddai)
	{
		dda->map.x = (int)(ray->pos.x) >> 6;
		dda->map.y = (int)(ray->pos.y) >> 6;
		if (dda->map.x >= 0 && dda->map.x < w && dda->map.y >= 0 && dda->map.y < h && \
				r->world->map[(int)dda->map.y][(int)dda->map.x] == '1')
		{
			if (hor)
				dda->distance.y = dist(p->pos, ray->pos);
			else
				dda->distance.x = dist(p->pos, ray->pos);
			dda->ddai = 0;
		}
		else
		{
			vec2_add(&ray->pos, ray->offset);
			dda->ddai--;
		}
	}
}

void	dda_algorithm(t_renderer *r, t_player *player, t_ray *ray, t_dda *dda)
{
	setup_vertical_dda(r, player, dda, ray);
	dda_loop(r, false, dda, ray, player);
	dda->vert.x = ray->pos.x;
	dda->vert.y = ray->pos.y;
	setup_horizontal_dda(r, player, dda, ray);
	dda_loop(r, true, dda, ray, player);
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
