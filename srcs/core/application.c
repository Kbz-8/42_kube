/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:58:41 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 03:32:04 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <input.h>
#include <stdlib.h>
#include <application.h>

void	init_application(t_application *app)
{
	t_renderer	*renderer;
	t_platform	*plat;

	renderer = init_renderer(NULL, NULL);
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
