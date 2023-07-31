/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:31:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/31 18:10:32 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include"../../third_party/libft/libft.h"
#include "../../includes/errors.h"

void	parse(int ac, char **av)
{
	if (ac != 2)
		report(FATAL_ERROR, E_NAME);
	if (ft_strlen(av[1]) == 0)
		report(FATAL_ERROR, E_NAME);
	if (ft_strrchr(av[1], '.') == NULL)
		report(FATAL_ERROR, E_NAME);
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub") != 0)
		report(FATAL_ERROR, E_NAME);
	if (ft_strlen(ft_strrchr(av[1], '.')) != 4)
		report(FATAL_ERROR, E_NAME);
}
