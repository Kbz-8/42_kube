/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:46:05 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/08 16:44:57 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <libft.h>
#include <parser.h>
#include <stdbool.h>
#include <memory.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errors.h>
#include <unistd.h>

void	check_textures_paths(char **file)
{
	int fd;

	fd = open(fetch_path(fetch_line(file, "NO")), O_RDONLY);
	if (fd == -1)
		report(FATAL_ERROR, INVALID_PATH);
	close(fd);
	fd = open(fetch_path(fetch_line(file, "SO")), O_RDONLY);
	if (fd == -1)
		report(FATAL_ERROR, INVALID_PATH);
	close(fd);
	fd = open(fetch_path(fetch_line(file, "WE")), O_RDONLY);
	if (fd == -1)
		report(FATAL_ERROR, INVALID_PATH);
	close(fd);
	fd = open(fetch_path(fetch_line(file, "EA")), O_RDONLY);
	if (fd == -1)
		report(FATAL_ERROR, INVALID_PATH);
	close(fd);
}

t_textures_files	*get_textures_path(char **file)
{
	t_textures_files *path;

	check_textures_paths(file);
	path = alloc(sizeof(t_textures_files));
	path->north = fetch_path(fetch_line(file, "NO"));
	path->south = fetch_path(fetch_line(file, "SO"));
	path->west = fetch_path(fetch_line(file, "WE"));
	path->east = fetch_path(fetch_line(file, "EA"));
	return (path);
}

bool	ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (str[i] == 0)
		return (true);
	if (str[i + 1] == 0)
		return (true);
	else
		return (false);
}

void	check_color_buff(char **buffer)
{
	if (!buffer || buffer[0] == NULL | buffer[1] == NULL || buffer[2] == NULL)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (buffer[3] == NULL || buffer[4] != NULL)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (!ft_isnumber(buffer[1]) || !ft_isnumber(buffer[2]) || \
	!ft_isnumber(buffer[3]))
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
}
void	get_colors(t_color *floor, t_color *ceiling, char **file)
{
	char **buffer;

	buffer = ft_splits(jump_space(fetch_line(file, "F")), " ,");
	check_color_buff(buffer);
	floor->r = ft_atoi(buffer[1]);
	floor->g = ft_atoi(buffer[2]);
	floor->b = ft_atoi(buffer[3]);
	buffer = ft_splits(jump_space(fetch_line(file, "C")), " ,");
	check_color_buff(buffer);
	ceiling->r = ft_atoi(buffer[1]);
	ceiling->g = ft_atoi(buffer[2]);
	ceiling->b = ft_atoi(buffer[3]);
}
