/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:52:53 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/09 17:08:52 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>
#include <renderer.h>
#include <errors.h>

char	get_last_char(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	if (i == 0)
		return (line[i]);
	return (line[i - 1]);
}

char	*jump_space(char *path)
{
	int i;

	i = 0;
	while (path && path[i] && path[i] == ' ')
		i++;
	return (&path[i]);
}

bool	is_texture_name(char *str)
{
	if (jump_space(str) == NULL)
		return (false);
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

int	get_max_len(uint8_t **map)
{
	int i;
	int max;

	i = 0;
	max = ft_strlen((char *)map[i]);
	while (map[i])
	{
		if (max < (int)ft_strlen((char *)map[i]))
			max = (int)ft_strlen((char *)map[i]);
		i++;
	}
	return (max);
}