/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:46:05 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/08 14:50:36 by vvaas            ###   ########.fr       */
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

void	get_colors(t_color *floor, t_color *ceiling, char **file)
{
	char **buffer;

	buffer = ft_split(jump_space(fetch_line(file, "F")), ',');
	floor->r = ft_atoi(buffer[0]);
	floor->g = ft_atoi(buffer[1]);
	floor->b = ft_atoi(buffer[2]);
	buffer = ft_split(jump_space(fetch_line(file, "C")), ',');
	ceiling->r = ft_atoi(buffer[0]);
	ceiling->g = ft_atoi(buffer[1]);
	ceiling->b = ft_atoi(buffer[2]);
}
