/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:39:45 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/12 15:30:50 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <memory.h>
#include <renderer.h>
#include <libft.h>

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
	t_renderer	*r;
	int			dummy;

	r = alloc(sizeof(t_renderer));
	r->world = world;
	r->plat = alloc(sizeof(t_platform));
	init_platform(r->plat);
	r->tex[0].img = mlx_jpg_file_to_image(r->plat->mlx, textures->north, \
														&dummy, &dummy);
	r->tex[1].img = mlx_jpg_file_to_image(r->plat->mlx, textures->south, \
														&dummy, &dummy);
	r->tex[2].img = mlx_jpg_file_to_image(r->plat->mlx, textures->west, \
														&dummy, &dummy);
	r->tex[3].img = mlx_jpg_file_to_image(r->plat->mlx, textures->east, \
														&dummy, &dummy);
	return (r);
}

void	destroy_renderer(t_renderer *renderer)
{
	mlx_destroy_image(renderer->plat->mlx, renderer->tex[0].img);
	mlx_destroy_image(renderer->plat->mlx, renderer->tex[1].img);
	mlx_destroy_image(renderer->plat->mlx, renderer->tex[2].img);
	mlx_destroy_image(renderer->plat->mlx, renderer->tex[3].img);
	destroy_platform(renderer->plat);
}
