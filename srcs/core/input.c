/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:13:02 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 15:22:20 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <input.h>
#include <stdio.h>
#include <utils.h>

#define W 26
#define S 22
#define Q 4
#define D 7
#define LEFT 80
#define RIGHT 79

int	keydown_hook(int key, t_application *app)
{
	if (key == 41)
		mlx_loop_end(app->renderer->plat->mlx);
	if (key == W)
		app->events_states[KEY_W] = true;
	if (key == S)
		app->events_states[KEY_S] = true;
	if (key == Q)
		app->events_states[KEY_Q] = true;
	if (key == D)
		app->events_states[KEY_D] = true;
	if (key == LEFT)
		app->events_states[KEY_LEFT] = true;
	if (key == RIGHT)
		app->events_states[KEY_RIGHT] = true;
	return (0);
}

int	keyup_hook(int key, t_application *app)
{
	if (key == W)
		app->events_states[KEY_W] = false;
	if (key == S)
		app->events_states[KEY_S] = false;
	if (key == Q)
		app->events_states[KEY_Q] = false;
	if (key == D)
		app->events_states[KEY_D] = false;
	if (key == LEFT)
		app->events_states[KEY_LEFT] = false;
	if (key == RIGHT)
		app->events_states[KEY_RIGHT] = false;
	return (0);
}

int	window_hook(int event, t_application *app)
{
	if (event == 0)
		mlx_loop_end(app->renderer->plat->mlx);
	return (0);
}
