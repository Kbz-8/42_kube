/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:58:41 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 08:01:08 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <input.h>
#include <stdlib.h>
#include <memory.h>
#include <application.h>

int map[] = {
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,1,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

void	init_application(t_application *app)
{
	t_renderer	*renderer;
	t_platform	*plat;
	// tmp -----------------------------
	t_world		*world;

	world = alloc(sizeof(t_world));
	world->floor.r = 128; world->floor.g = 128; world->floor.b = 128;
	world->ceiling.r = 100; world->ceiling.g = 100; world->ceiling.b = 100;
	world->map = alloc(64);
	for(int i = 0; i < 8; i++)
	{
		world->map[i] = alloc(8);
		for(int j = 0; j < 8; j++)
			world->map[i][j] = (uint8_t)map[(i * 8) + j];
	}
	// tmp -----------------------------
	renderer = init_renderer(NULL, world);
	plat = renderer->plat;
	app->renderer = renderer;
	mlx_on_event(plat->mlx, plat->win, MLX_KEYDOWN, key_hook, app);
	mlx_on_event(plat->mlx, plat->win, MLX_WINDOW_EVENT, window_hook, app);
}

void	run(t_application *app)
{
	mlx_loop_hook(app->renderer->plat->mlx, update, app);
	mlx_loop(app->renderer->plat->mlx);
}

int	update(t_application *app)
{
	render(app->renderer);
	return (0);
}

void	destroy_application(t_application *app)
{
	destroy_renderer(app->renderer);
}
