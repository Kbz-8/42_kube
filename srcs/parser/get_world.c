/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:43:56 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/11 14:11:15 by vvaas            ###   ########.fr       */
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

uint8_t	**get_map(char **file, size_t *size_x, size_t *size_y)
{
	int	i;

	i = 0;
	while (file[i] && is_texture_name(file[i]))
		i++;
	is_a_map(&file[i]);
	return (convert_map(&file[i], size_x, size_y));
}
