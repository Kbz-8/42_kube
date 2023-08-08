/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:05:54 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/08 12:15:28 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <parser.h>
#include <errors.h>

uint8_t	**get_map(char **file, size_t *size_x, size_t *size_y)
{
	int i;

	i = 0;

	while (is_texture_name(file[i]))
		i++;
	is_a_map(&file[i]);
	return (convert_map(&file[i], size_x, size_y));
}

bool	is_a_map(char **file)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (file[i])
	{
		while (file[i][j])
		{
			if (!is_map_character(file[i][j]))
				return (false);
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

bool	is_map_character(char c)
{
	static bool dir = 0;

	if ((c == 'N' && dir) || (c == 'W' && dir) || (c == 'E' && dir))
		report(FATAL_ERROR, INVALID_MAP);
	if (c == 'S' && dir)
		report(FATAL_ERROR, INVALID_MAP);
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
	{
		dir = 1;
		return (true);
	}
	if (c == '0' || c == '1' || c == ' ' || c == '\n')
		return (true);
	report(FATAL_ERROR, INVALID_MAP);
	return (false);
}

uint8_t	**convert_map(char **file, size_t *size_x, size_t *size_y)
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
