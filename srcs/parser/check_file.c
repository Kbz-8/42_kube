/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:07:20 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/07 02:49:14 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <memory.h>
#include <libft.h>
#include <parser.h>
#include <errors.h>
#include <renderer.h>

t_textures_files	*get_textures_path(char **file);

bool	in_order(char **file)
{
	int i;
//	int count;

//	count = 0;
	i = 0;
	while (is_texture_name(file[i]))
		i++;
	return (is_a_map(&file[i]));
}

void	check_texture_amount(t_parse *texture)
{
	if (texture->N_textures != 1 || texture->S_textures != 1)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (texture->E_textures != 1 || texture->W_textures != 1)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (texture->C_color != 1 || texture->F_color != 1)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
}

void	texture_path(t_parse *texture, char **file)
{
	int i;
	i = 0;
	ft_memset(texture, 0, sizeof(t_parse));
	while (file[i])
	{
		if (ft_strncmp(jump_space(file[i]), "NO", 2) == 0)
			texture->N_textures++;
		if (ft_strncmp(jump_space(file[i]), "SO", 2) == 0)
			texture->S_textures++;
		if (ft_strncmp(jump_space(file[i]), "WE", 2) == 0)
			texture->W_textures++;
		if (ft_strncmp(jump_space(file[i]), "EA", 2) == 0)
			texture->E_textures++;
		if (ft_strncmp(jump_space(file[i]), "F", 1) == 0)
			texture->F_color++;
		if (ft_strncmp(jump_space(file[i]), "C", 1) == 0)
			texture->C_color++;
	i++;
	}
	check_texture_amount(texture);
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
