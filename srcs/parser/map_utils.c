/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:05:54 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/09 16:57:44 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <parser.h>
#include <errors.h>
#include <memory.h>
#include <libft.h>

bool	is_dir_char(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

bool	is_a_map(char **file)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	j = 0;
	contain_invalid_chars(file);
	while (file[i])
	{
		while (file[i][j])
		{
			if (!is_map_character(file[i][j]))
				return (false);
			if (is_dir_char(file[i][j]))
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		report(FATAL_ERROR, INVALID_MAP);
	return (true);
}

bool	is_map_character(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (true);
	if (c == '0' || c == '1' || c == ' ' || c == '\n')
		return (true);
	report(FATAL_ERROR, INVALID_MAP);
	return (false);
}

bool	is_map_component(char *str)
{
	if (jump_space(str)[0] == '\n' || !jump_space(str)[0])
		return (false);
	return (true);
}

uint8_t	**cut_end_map(char **file, int width)
{
	int i;
	uint8_t **map;

	i = 0;
	map = alloc(width * (sizeof(uint8_t *) + 1));
	while (i < width)
	{
		map[i] = (uint8_t *)ft_strdup(file[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

uint8_t	**convert_map(char **file, size_t *size_x, size_t *size_y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*size_y = 0;
	while (file[i] && is_map_component(file[i]))
	{
		*size_x = 0;
		while (file[i][j])
		{
			if (file[i][j] == '\n')
				file[i][j] = 0;
			j++;
			(*size_x)++;
		}
		j = 0;
		i++;
		(*size_y)++;
	}
	return (cut_end_map(file, i));
}
