/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:50:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/06 23:43:25 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>
#include <stdlib.h>
#include <parser.h>
#include <application.h>
#include <unistd.h>

void	print_debug(char **av)
{
	int i;
	t_textures_files *color;
	t_world			*world;

	i = 0;
	color = get_textures_path(get_file(av));
	world = create_world(get_file(av));
	ft_printf("E :%s\nN :%s\nS :%s\nW :%s\n---MAP---\n\n", color->east, color->north, color->south,color->west);
	while (world->map[i])
		ft_printf("%s\n", world->map[i++]);
}

int	main(int ac, char **av)
{
	t_application	app;
	bool debug = true;

	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
	parse(ac, av);
	if (debug)
		print_debug(av);
	init_application(&app); //get_texture_path(PATH DE LA MAP) te donne les t_textures_file et create_world(PATH DE LA MAP) le t_world
	run(&app);
	destroy_application(&app);
	allfree();
	return (0);
}
