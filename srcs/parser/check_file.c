/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:07:20 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/12 14:12:12 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <memory.h>
#include <libft.h>
#include <parser.h>
#include <errors.h>
#include <renderer.h>

bool	in_order(char **file)
{
	int	i;

	i = 0;
	while (is_texture_name(file[i]))
		i++;
	return (is_a_map(&file[i]));
}

void	check_texture_amount(t_parse *texture)
{
	if (texture->n_textures != 1 || texture->s_textures != 1)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (texture->e_textures != 1 || texture->w_textures != 1)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
	if (texture->c_color != 1 || texture->f_color != 1)
		report(FATAL_ERROR, INVALID_CONFIG_FILE);
}

void	texture_path(t_parse *texture, char **file)
{
	int	i;

	i = 0;
	ft_memset(texture, 0, sizeof(t_parse));
	while (file[i])
	{
		if (jump_space(file[i]) == NULL)
			continue ;
		if (ft_strncmp(jump_space(file[i]), "NO", 2) == 0)
			texture->n_textures++;
		if (ft_strncmp(jump_space(file[i]), "SO", 2) == 0)
			texture->s_textures++;
		if (ft_strncmp(jump_space(file[i]), "WE", 2) == 0)
			texture->w_textures++;
		if (ft_strncmp(jump_space(file[i]), "EA", 2) == 0)
			texture->e_textures++;
		if (ft_strncmp(jump_space(file[i]), "F", 1) == 0)
			texture->f_color++;
		if (ft_strncmp(jump_space(file[i]), "C", 1) == 0)
			texture->c_color++;
	i++;
	}
	check_texture_amount(texture);
}

bool	check_file(char **file)
{
	int		i;
	t_parse	texture_list;

	i = 0;
	while (file[i] && file[i][0] == '\n' && file[i][0] != '\0')
		file[i++][0] = ' ';
	i = 0;
	texture_path(&texture_list, file);
	return (true);
}
