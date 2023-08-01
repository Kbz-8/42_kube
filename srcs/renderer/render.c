/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:31:11 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 08:01:31 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <renderer.h>

void	render(t_renderer *renderer)
{
	mlx_clear_window(renderer->plat->mlx, renderer->plat->win);
	//mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, 100, 100, 0x00FF00FF);
	int xo, yo;
	int color;
	for(int y = 0; y < 8; y++)
	{
		for(int x = 0; x < 8; x++)
		{
			if(renderer->world->map[x][y] == 1)
				color = 0x00444444;
			else
				color = 0x00FFFFFF;
			xo = x * 64;
			yo = y * 64;
			for(int i = xo + 1; i < 64 + xo - 1; i++)
			{
				for(int j = yo + 1; j < 64 + yo - 1; j++)
					mlx_pixel_put(renderer->plat->mlx, renderer->plat->win, j, i, color);
			}
		} 
	} 
}
