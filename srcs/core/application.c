/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:58:41 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/08 23:25:31 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <input.h>
#include <libft.h>
#include <stdlib.h>
#include <memory.h>
#include <application.h>

#define SPEED	4.f
#define SENSI	0.1f

static void	move(t_application *app)
{
	if (app->events_states[KEY_W])
		vec2_add(&app->player.pos, vec2_mul_n_copy(app->player.dir, SPEED));
	if (app->events_states[KEY_S])
		vec2_sub(&app->player.pos, vec2_mul_n_copy(app->player.dir, SPEED));
	if (app->events_states[KEY_Q])
		vec2_sub(&app->player.pos, vec2_mul_n_copy(app->player.left, SPEED));
	if (app->events_states[KEY_D])
		vec2_add(&app->player.pos, vec2_mul_n_copy(app->player.left, SPEED));
	if (app->events_states[KEY_LEFT])
		app->player.angle += SENSI;
	if (app->events_states[KEY_RIGHT])
		app->player.angle -= SENSI;
	app->player.angle = fix_ang(app->player.angle);
	app->player.dir.x = cos(app->player.angle);
	app->player.dir.y = -sin(app->player.angle);
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
