/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:05:54 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/11 14:20:42 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <parser.h>
#include <errors.h>
#include <memory.h>
#include <libft.h>

bool	is_a_map(char **file)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	contain_invalid_chars(file);
	while (file[i])
	{
		if (file[i][0] == '\n')
			break ;
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
	check_eof(&file[i], count);
	return (true);
}

uint8_t	**cut_end_map(char **file, int width)
{
	int		i;
	uint8_t	**map;

	i = 0;
	map = alloc(width * (sizeof(uint8_t *)));
	while (i < width)
	{
		map[i] = (uint8_t *)ft_strdup(file[i]);
		i++;
	}
	return (map);
}

uint8_t	**convert_map(char **file, size_t *size_x, size_t *size_y)
{
	int	i;
	int	j;

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
