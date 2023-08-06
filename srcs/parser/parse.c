/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:31:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/06 21:25:48 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <libft.h>
#include <errors.h>
#include <renderer.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>

int	ft_charcount(char *str, char character)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == character)
			count++;
		i++;
	}
	return (count);
}

char	**get_file(char **av)
{
	int		fd;
	char	*buffer;
	char	**file;
	int i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		report(FATAL_ERROR, NO_FILE);
	buffer = get_next_line(fd);
	while (buffer)
		buffer = ft_strjoin(buffer, get_next_line(fd));
	file = alloc(sizeof(char *) * (ft_charcount(buffer, '\n') + 1));
	close(fd);
	fd = open(av[1], O_RDONLY);
	file[i] = get_next_line(fd);
	while (file[i])
		file[++i] = get_next_line(fd);
	close(fd);
	return (file);
}

void	name_parse(char **av)
{
	if (ft_strlen(av[1]) == 0)
		report(FATAL_ERROR, E_NAME);
	if (ft_strrchr(av[1], '.') == NULL)
		report(FATAL_ERROR, E_NAME);
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub") != 0)
		report(FATAL_ERROR, E_NAME);
	if (ft_strlen(ft_strrchr(av[1], '.')) != 4)
		report(FATAL_ERROR, E_NAME);
}


void	parse(int ac, char **av)
{
//	char **file;

	if (ac == 1)
		report(FATAL_ERROR, E_NO_ARGS);
	if (ac != 2)
		report(FATAL_ERROR, E_TOO_MANY_ARGS);
	name_parse(av);
//	file = get_file(av);
}
