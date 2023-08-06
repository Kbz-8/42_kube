/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:52:53 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/06 23:22:19 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>
#include <renderer.h>
#include <errors.h>

char	*jump_space(char *path)
{
	int i;

	i = 0;
	while (path && path[i] && path[i] == ' ')
		i++;
	return (&path[i]);
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

bool	is_texture_name(char *str)
{
	if (ft_strncmp(jump_space(str), "NO", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "SO", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "WE", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "EA", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "C", 1) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "F", 1) == 0)
		return (true);
	if (jump_space(str)[0] == '\n' || jump_space(str)[0] == '\0')
		return (true);
	return (false);
}