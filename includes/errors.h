/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:31 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/06 20:27:00 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERRORS_H
# define ERRORS_H

# define E_UNKOWN				0
# define E_MEMFAIL				1
# define E_TOO_MANY_ARGS		2
# define E_NAME					3
# define E_NO_ARGS				4
# define NO_FILE				5
# define INVALID_CONFIG_FILE	6

enum	e_type
{
	ERROR,
	FATAL_ERROR
};

void	report(enum e_type type, int error);

#endif
