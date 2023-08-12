/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:05:54 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/12 15:40:58 by vvaas            ###   ########.fr       */
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
		if (jump_space(file[i])[0] == '\n')
			break ;
		while (file[i][j] && is_map_character(file[i][j]))
		{
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

int	longest_line(char **file)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (file[i] && is_map_component(file[i]))
	{
		if (max < (int)ft_strlen(file[i]))
			max = (int)ft_strlen(file[i]);
		i++;
	}
	return (max);
}

uint8_t	**cut_end_map(char **file, int width, size_t *x, size_t *y)
{
	int		i;
	uint8_t	**map;
	int		max;

	max = longest_line(file);
	*x = max;
	*y = width;
	i = 0;
	map = alloc(width * (sizeof(uint8_t *)));
	while (i < width)
	{
		map[i] = alloc(sizeof(char) * (max + 1));
		ft_strcpy((char *)map[i], file[i]);
		while ((int)ft_strlen((char *)map[i]) < max)
			map[i][ft_strlen((char *)map[i])] = '0';
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
	while (file[i] && is_map_component(file[i]))
	{
		while (file[i][j])
		{
			if (file[i][j] == '\n')
				file[i][j] = 0;
			if (file[i][j] == ' ')
				file[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
	return (cut_end_map(file, i, size_x, size_y));
}
