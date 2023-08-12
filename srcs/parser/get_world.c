/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:43:56 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/12 14:35:12 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <parser.h>
#include <libft.h>
#include <memory.h>

int	get_pos(char **file, bool x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		while (file[i][j])
		{
			if (is_dir_char(file[i][j]))
				return (x * j + !x * i);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

t_world	*create_world(char **file)
{
	t_world	*world;
	int		i;

	i = 0;
	world = alloc(sizeof(t_world));
	get_colors(&world->floor, &world->ceiling, file);
	world->map = get_map(file, &world->map_x_size, &world->map_y_size);
	while (file[i] && is_texture_name(file[i]))
		i++;
	world->player_init_y = get_pos(&file[i], false);
	world->player_init_x = get_pos(&file[i], true);
	world->player_orientation = file[world->player_init_y + i] \
	[world->player_init_x];
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
