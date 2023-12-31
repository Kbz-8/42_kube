/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:31:31 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/11 14:09:04 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <libft.h>
#include <errors.h>
#include <renderer.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include <parser.h>

void	name_parse(char **av)
{
	if (ft_strlen(av[1]) == 0)
		report(FATAL_ERROR, E_NAME);
	if (ft_strrchr(av[1], '.') == NULL)
		report(FATAL_ERROR, E_NAME);
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub") != 0)
		report(FATAL_ERROR, E_NAME);
	if (ft_strlen(ft_strrchr(av[1], '.')) != 4)
		report(FATAL_ERROR, E_NAME);
}

void	parse(int ac, char **av)
{
	if (ac == 1)
		report(FATAL_ERROR, E_NO_ARGS);
	if (ac != 2)
		report(FATAL_ERROR, E_TOO_MANY_ARGS);
	name_parse(av);
	if (!check_file(get_file(av)))
		report(FATAL_ERROR, INVALID_MAP);
}
