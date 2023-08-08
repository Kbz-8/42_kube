/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:52:53 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/08 12:12:26 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>
#include <renderer.h>
#include <errors.h>

char	*jump_space(char *path)
{
	int i;

	i = 0;
	while (path && path[i] && path[i] == ' ')
		i++;
	return (&path[i]);
}

bool	is_texture_name(char *str)
{
	if (ft_strncmp(jump_space(str), "NO", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "SO", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "WE", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "EA", 2) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "C", 1) == 0)
		return (true);
	if (ft_strncmp(jump_space(str), "F", 1) == 0)
		return (true);
	if (jump_space(str)[0] == '\n' || jump_space(str)[0] == '\0')
		return (true);
	return (false);
}