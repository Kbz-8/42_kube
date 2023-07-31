/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:39:45 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/31 18:09:01 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>

t_renderer	*init_renderer(t_textures_files *textures, t_world *world)
{
	t_renderer	*renderer;

	renderer = alloc(sizeof(t_renderer));
	renderer->world = world;
	return (renderer);
}
