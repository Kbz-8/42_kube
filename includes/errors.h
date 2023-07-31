/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:31 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/31 17:26:40 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERRORS_H
# define ERRORS_H

# define E_UNKOWN			0
# define E_MEMFAIL			1
# define E_TOO_MANY_ARGS	3

enum	e_type
{
	ERROR,
	FATAL_ERROR
};

void	report(enum e_type type, int error);

#endif
