/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:50:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 17:11:12 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>
#include <stdlib.h>
#include <parser.h>
#include <application.h>
#include <unistd.h>

#ifdef DEBUG
static const bool debug = true;
#else
static const bool debug = false;
#endif

void	print_debug(char **av)
{
	int i;
	t_textures_files *color;
	t_world			*world;

	i = 0;
	color = get_textures_path(get_file(av));
	world = create_world(get_file(av));
	ft_printf("E :%s\nN :%s\nS :%s\nW :%s\n---MAP---\n\n", color->east, color->north, color->south,color->west);
	ft_printf("Size x : %d\nSize y : %d\n", world->map_x_size, world->map_y_size);
	while (world->map[i])
		ft_printf("%s\n", world->map[i++]);
}

int	main(int ac, char **av)
{
	t_application	app;
	char			**file;

	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
	parse(ac, av);
	if (debug)
		print_debug(av);
	file = get_file(av);
	init_application(&app, get_textures_path(file), create_world(file));
	run(&app);
	destroy_application(&app);
	allfree();
	return (0);
}
