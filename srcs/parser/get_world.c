/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:43:56 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/08 12:15:55 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <parser.h>
#include <libft.h>
#include <memory.h>

t_world	*create_world(char **file)
{
	t_world	*world;

	world = alloc(sizeof(t_world));
	get_colors(&world->floor, &world->ceiling, file);
	world->map = get_map(file, &world->map_x_size, &world->map_y_size);
	return (world);
}
