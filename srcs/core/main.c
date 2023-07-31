/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:50:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/31 21:25:41 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>
#include <stdlib.h>
#include <parser.h>
#include <renderer.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_renderer	*renderer;

	parse(ac, av);
	renderer = init_renderer(NULL, NULL);
	usleep(2000000);
	destroy_renderer(renderer);
	allfree();
	return (0);
}
