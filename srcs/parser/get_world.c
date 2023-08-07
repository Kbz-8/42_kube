/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:43:56 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/07 03:13:53 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <parser.h>
#include <libft.h>
#include <memory.h>

static uint8_t	**convert_map(char **file, size_t *size_x, size_t *size_y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*size_y = 0;
	while (file[i])
	{
		*size_x = 0;
		while (file[i][j])
		{
			if (file[i][j] == ' ')
				file[i][j] = '0';
			if (file[i][j] == '\n')
				file[i][j] = 0;
			j++;
			(*size_x)++;
		}
		j = 0;
		i++;
		(*size_y)++;
	}
	return ((uint8_t **)file);
}

uint8_t	**get_map(char **file, size_t *size_x, size_t *size_y)
{
	int i;

	i = 0;

	while (is_texture_name(file[i]))
		i++;
	is_a_map(&file[i]);
	return (convert_map(&file[i], size_x, size_y));
	
}

void	get_colors(t_color *floor, t_color *ceiling, char **file)
{
	char **buffer;

	buffer = ft_split(jump_space(fetch_line(file, "F")), ',');
	floor->r = ft_atoi(buffer[0]);
	floor->g = ft_atoi(buffer[1]);
	floor->b = ft_atoi(buffer[2]);
	buffer = ft_split(jump_space(fetch_line(file, "C")), ',');
	ceiling->r = ft_atoi(buffer[0]);
	ceiling->g = ft_atoi(buffer[1]);
	ceiling->b = ft_atoi(buffer[2]);
}

t_world	*create_world(char **file)
{
	t_world	*world;

	world = alloc(sizeof(t_world));
	get_colors(&world->floor, &world->ceiling, file);
	world->map = get_map(file, &world->map_x_size, &world->map_y_size);
	return (world);
}
