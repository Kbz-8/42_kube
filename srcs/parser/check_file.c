/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:07:20 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/06 20:24:21 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <memory.h>
#include <libft.h>
#include <parser.h>
#include <errors.h>

void	texture_path(t_parse *texture, char **file)
{
	int i;

	i = 0;
	ft_memset(texture, 0, sizeof(t_parse));
	while (file[i])
	{
		if (ft_strncmp(file[i], "NO", 2) == 0)
			texture->N_textures++;
		if (ft_strncmp(file[i], "SO", 2) == 0)
			texture->S_textures++;
		if (ft_strncmp(file[i], "WE", 2) == 0)
			texture->W_textures++;
		if (ft_strncmp(file[i], "EA", 2) == 0)
			texture->E_textures++;
		if (ft_strncmp(file[i], "F", 1) == 0)
			texture->F_color++;
		if (ft_strncmp(file[i], "C", 1) == 0)
			texture->C_color++;
	i++;
	}
}

bool	check_file(char **file)
{
	int		i;
	t_parse	texture_list;

	i = 0;
	while (file[i][0] == '\n' && file[i][0] != '\0')
		file[i++][0] = ' ';
	i = 0;
	texture_path(&texture_list, file);
	return (true);
}
