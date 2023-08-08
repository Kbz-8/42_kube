/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:04:48 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/08 12:14:53 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errors.h>
#include <sys/types.h>
#include <fcntl.h>
#include <parser.h>
#include <memory.h>
#include <unistd.h>

char	*fetch_path(char *line)
{
	int i;

	i = 0;
	line = jump_space(jump_space(line) + 2);
	while (line[i] && line[i] != ' ' && line[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
	return (ft_strndup(line, i));
}

char	*fetch_line(char **file, char *target)
{
	int i;

	i = 0;
	while (file[i])
	{
		if (ft_strncmp(jump_space(file[i]), target, ft_strlen(target)) == 0)
			return (file[i]);
		i++;
	}
	return (NULL);

}

char	**get_file(char **av)
{
	int		fd;
	char	*buffer;
	char	*tmp;
	char	**file;
	int i;

	i = 0;
	buffer = alloc(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		report(FATAL_ERROR, NO_FILE);
	tmp = get_next_line(fd);
	while (tmp)
	{
		buffer = ft_strjoin(buffer, tmp);
		tmp = get_next_line(fd);
	}
	buffer = ft_strjoin(buffer, "\0");
	file = alloc(sizeof(char *) * (ft_charcount(buffer, '\n') + 2));
	close(fd);
	fd = open(av[1], O_RDONLY);
	file[i] = get_next_line(fd);
	while (file[i])
		file[++i] = get_next_line(fd);
	file[i] = NULL;
	close(fd);
	return (file);
}

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
