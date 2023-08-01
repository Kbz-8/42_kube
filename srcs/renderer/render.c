/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:31:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 03:31:57 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <renderer.h>

void	render(t_renderer *renderer)
{
	mlx_clear_window(renderer->plat->mlx, renderer->plat->win);
}
