/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:50:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/06 20:18:53 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>
#include <stdlib.h>
#include <parser.h>
#include <application.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_application	app;

	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
	parse(ac, av);
	init_application(&app);
	run(&app);
	destroy_application(&app);
	allfree();
	return (0);
}
