/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:46:05 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/06 22:57:22 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
#include <libft.h>
#include <parser.h>
#include <stdbool.h>
#include <memory.h>

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

t_textures_files	*get_textures_path(char **file)
{
	t_textures_files *path;

	path = alloc(sizeof(t_textures_files));
	path->north = fetch_path(fetch_line(file, "NO"));
	path->south = fetch_path(fetch_line(file, "SO"));
	path->west = fetch_path(fetch_line(file, "WE"));
	path->east = fetch_path(fetch_line(file, "EA"));
	return (path);
}