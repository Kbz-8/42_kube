/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:46:05 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/11 15:07:22 by vvaas            ###   ########.fr       */
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
	int	fd;

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

void	check_after_path(char *str, char *path)
{
	if (str[2] != ' ')
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (jump_space(jump_space(str + 2) + ft_strlen(path))[0] != '\n')
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
}

t_textures_files	*get_textures_path(char **file)
{
	t_textures_files	*path;

	check_textures_paths(file);
	path = alloc(sizeof(t_textures_files));
	path->north = fetch_path(fetch_line(file, "NO"));
	check_after_path(fetch_line(file, "NO"), path->north);
	path->south = fetch_path(fetch_line(file, "SO"));
	check_after_path(fetch_line(file, "SO"), path->north);
	path->west = fetch_path(fetch_line(file, "WE"));
	check_after_path(fetch_line(file, "WE"), path->north);
	path->east = fetch_path(fetch_line(file, "EA"));
	check_after_path(fetch_line(file, "EA"), path->north);
	return (path);
}

void	check_color_buff(char **buffer)
{
	if (!buffer || buffer[0] == NULL | buffer[1] == NULL || buffer[2] == NULL)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (buffer[3] == NULL || (buffer[4] != NULL && buffer[4][0] != '\n'))
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (!ft_isnumber(buffer[1]) || !ft_isnumber(buffer[2]) || \
	!ft_isnumber(buffer[3]))
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (ft_atoi(buffer[1]) > 255 || ft_atoi(buffer[2]) > 255 || \
	ft_atoi(buffer[3]) > 255)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
}

void	get_colors(t_color *floor, t_color *ceiling, char **file)
{
	char	**buffer;

	buffer = ft_splits(jump_space(fetch_line(file, "F")), " ,");
	check_color_buff(buffer);
	floor->r = ft_atoi(buffer[1]);
	floor->g = ft_atoi(buffer[2]);
	floor->b = ft_atoi(buffer[3]);
	if (floor->r > 255 || floor->g > 255 || floor->b > 255)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	buffer = ft_splits(jump_space(fetch_line(file, "C")), " ,");
	check_color_buff(buffer);
	ceiling->r = ft_atoi(buffer[1]);
	ceiling->g = ft_atoi(buffer[2]);
	ceiling->b = ft_atoi(buffer[3]);
	if (floor->r > 255 || floor->g > 255 || floor->b > 255)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
}
