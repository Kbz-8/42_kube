/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:17:38 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/12 14:36:51 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdbool.h>
#include <errors.h>

bool	is_dir_char(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

bool	check_eof(char **file, int count)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (jump_space(file[i])[0] != '\n' && jump_space(file[i])[0] != '\0')
			report(FATAL_ERROR, INVALID_CONFIG_FILE);
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
