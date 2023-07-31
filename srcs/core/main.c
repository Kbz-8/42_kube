/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:50:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/31 18:05:43 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>
#include <parser.h>

int	main(int ac, char **av)
{
	parse(ac, av);

	ft_printf("caca prout mdr\n");
	return (0);
}
