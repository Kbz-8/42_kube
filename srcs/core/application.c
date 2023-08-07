/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:58:41 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/07 03:21:02 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <input.h>
#include <libft.h>
#include <stdlib.h>
#include <memory.h>
#include <application.h>

static void	move(t_application *app)
{
	if (app->events_states[KEY_W])
		vec2_add(&app->player.pos, vec2_mul_n_copy(app->player.dir, 1.f));
	if (app->events_states[KEY_S])
		vec2_sub(&app->player.pos, vec2_mul_n_copy(app->player.dir, 1.f));
	if (app->events_states[KEY_Q])
		vec2_sub(&app->player.pos, vec2_mul_n_copy(app->player.left, 1.f));
	if (app->events_states[KEY_D])
		vec2_add(&app->player.pos, vec2_mul_n_copy(app->player.left, 1.f));
	if (app->events_states[KEY_LEFT])
		app->player.angle += 1;
	if (app->events_states[KEY_RIGHT])
		app->player.angle -= 1;
	app->player.angle = fix_ang(app->player.angle);
	app->player.dir.x = cos(deg_to_rad(app->player.angle));
	app->player.dir.y = -sin(deg_to_rad(app->player.angle));
	app->player.left.x = -app->player.dir.y;
	app->player.left.y = app->player.dir.x;
}

void	init_application(t_application *app, t_textures_files *tex, t_world *w)
{
	t_renderer	*renderer;
	t_platform	*plat;

	init_player(&app->player);
	ft_memset(app->events_states, 0, sizeof(app->events_states));
	renderer = init_renderer(tex, w);
	plat = renderer->plat;
	app->renderer = renderer;
	mlx_on_event(plat->mlx, plat->win, MLX_KEYUP, keyup_hook, app);
	mlx_on_event(plat->mlx, plat->win, MLX_KEYDOWN, keydown_hook, app);
	mlx_on_event(plat->mlx, plat->win, MLX_WINDOW_EVENT, window_hook, app);
}

void	run(t_application *app)
{
	mlx_loop_hook(app->renderer->plat->mlx, update, app);
	mlx_loop(app->renderer->plat->mlx);
}

int	update(t_application *app)
{
	move(app);
	render(app->renderer, &app->player);
	return (0);
}

void	destroy_application(t_application *app)
{
	destroy_renderer(app->renderer);
}
