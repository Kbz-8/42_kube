/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:58:26 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/12 15:12:50 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <libft.h>
#include <stdbool.h>
#include <parser.h>

static bool	valid_spaces(char **file, int i, int j)
{
	if (i < 0 || j < 0)
		return (true);
	if (file[i] == NULL)
		return (true);
	if (j >= (int)ft_strlen(file[i]))
		return (true);
	return (file[i][j] == '1' || file[i][j] == ' ' || file[i][j] == '\n' || \
	file[i][j] == '\0');
}

static bool	valid_floors(char **file, int i, int j)
{
	if (i < 0 || j < 0)
		return (false);
	if (file[i] == NULL)
		return (false);
	if (j == (int)ft_strlen(file[i]))
		return (false);
	return (file[i][j] != ' ' && file[i][j] != '\n' && file[i][j] != '\0');
}

static bool	char_valid(char **file, int i, int j, bool (*func)(char **, int, int))
{
	if (func(file, i + 1, j) && func(file, i - 1, j) && \
	func(file, i, j + 1) && func(file, i, j - 1))
		return (true);
	report(FATAL_ERROR, INVALID_MAP);
	return (false);
}

bool	contain_invalid_chars(char **file)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (file[i])
	{
		if (file[i][0] == '\n')
			break ;
		while (file[i][j])
		{
			if (file[i][j] == ' ')
				char_valid(file, i, j, &valid_spaces);
			if (file[i][j] == '0' || is_dir_char(file[i][j]))
				char_valid(file, i, j, &valid_floors);
			j++;
		}
		j = 0;
		i++;
	}
	return (false);
}
