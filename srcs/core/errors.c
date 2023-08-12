/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:46 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/12 13:46:22 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <stdlib.h>
#include <libft.h>
#include <memory.h>

#define ERRORS_NUMBER 9

static const char	*get_str_error(int error)
{
	static const char	*errors[ERRORS_NUMBER] = {
		"unknown error",
		"memory allocation failed",
		"too many arguments",
		"invalid map name",
		"no argument given",
		"argument is not a valid file",
		"file configuration is invalid",
		"map is invalid",
		"a path line is invalid"
	};

	return (errors[error]);
}

void	report(enum e_type type, int error)
{
	if (type == FATAL_ERROR)
		ft_putstr_fd("Error\nFatal Error : ", 2);
	else
		ft_putstr_fd("Error\nError : ", 2);
	if (error < 0 || error >= ERRORS_NUMBER)
		error = 0;
	ft_putstr_fd((char *)get_str_error(error), 2);
	ft_putchar_fd('\n', 2);
	if (type == FATAL_ERROR)
	{
		allfree();
		exit(EXIT_SUCCESS);
	}
}
