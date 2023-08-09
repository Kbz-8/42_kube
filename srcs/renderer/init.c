/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:39:45 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 05:00:21 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <memory.h>
#include <renderer.h>

static void	init_platform(t_platform *plat)
{
	plat->mlx = mlx_init();
	plat->win = mlx_new_window(plat->mlx, WIDTH, HEIGHT, "kube ? ;)");
}

static void	destroy_platform(t_platform *plat)
{
	mlx_destroy_window(plat->mlx, plat->win);
	mlx_destroy_display(plat->mlx);
}

t_renderer	*init_renderer(t_textures_files *textures, t_world *world)
{
	t_renderer	*renderer;

	(void)textures;
	renderer = alloc(sizeof(t_renderer));
	renderer->world = world;
	renderer->plat = alloc(sizeof(t_platform));
	init_platform(renderer->plat);
	//-----tmp-----
	renderer->tex[0].img = mlx_jpg_file_to_image(renderer->plat->mlx, "res/wall_0.jpg", &renderer->tex[0].w, &renderer->tex[0].h);
	//-----tmp-----
	return (renderer);
}

void	destroy_renderer(t_renderer *renderer)
{
	mlx_destroy_image(renderer->plat->mlx, renderer->tex[0].img);
	destroy_platform(renderer->plat);
}
