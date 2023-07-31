/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:07:20 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/31 22:45:20 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <libft.h>
#include <parser.h>

void	texture_path(t_parse *texture, char **file, int i)
{
	if (ft_strncmp(file[i], "NO", 2) == 0)
		
	if (ft_strncmp(file[i], "SO", 2) == 0)
	if (ft_strncmp(file[i], "WE", 2) == 0)
	if (ft_strncmp(file[i], "EA", 2) == 0)
}

bool	check_file(char **file)
{
	int		i;
	t_parse	*texture_list;

	i = 0;
	while (file[i][0] == '\n' && file[i][0] != '\0')
		file[i++][0] = ' ';
	i = 0;
	while (file[i])
	{
		texture_path(texture_list, file, i);
		i++;
	}
}
