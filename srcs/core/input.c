/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:13:02 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 03:15:53 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <input.h>

int	key_hook(int key, t_application *app)
{
	if (key == 41)
		mlx_loop_end(app->renderer->plat->mlx);
	return (0);
}

int	window_hook(int event, t_application *app)
{
	if (event == 0)
		mlx_loop_end(app->renderer->plat->mlx);
	return (0);
}
