/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:31:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/31 17:59:29 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include"../../third_party/libft/libft.h"

bool	parse(int *ac, char **av)
{
	if (ac != 2)
		return (0);
	if (ft_strlen(av[1]) == 0)
		return (0);
	if (ft_strcmp(ft_strchr(av[1], '.'), ".cub") != 0)
		return (0);
	if (ft_strlen(ft_strchr(av[1], '.')) != 5)
		return (0);
	return (1);
}
