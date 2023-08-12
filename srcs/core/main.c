/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:50:34 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/12 14:46:56 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>
#include <stdlib.h>
#include <parser.h>
#include <application.h>
#include <unistd.h>

void    print_debug(char **av)
{
    int i;
    t_textures_files *color;
    t_world            *world;

    i = 0;
    color = get_textures_path(get_file(av));
    world = create_world(get_file(av));
    ft_printf("E :%s\nN :%s\nS :%s\nW :%s\n---MAP---\n\n", color->east, color->north, color->south,color->west);
    ft_printf("F: %d,%d,%d\nC: %d,%d,%d\n", world->floor.r, world->floor.g, world->floor.b, world->ceiling.r, world->ceiling.g, world->ceiling.b);
    ft_printf("Size x : %d\nSize y : %d\n", world->map_x_size, world->map_y_size);
    while (world->map[i] != NULL)
        ft_printf("%s\n", world->map[i++]);
}

int	main(int ac, char **av)
{
	t_application	app;
	char			**file;

	ft_set_internal_malloc(alloc);
	ft_set_internal_free(dealloc);
	parse(ac, av);
	file = get_file(av);
	print_debug(av);
	init_application(&app, get_textures_path(file), create_world(file));
	run(&app);
	destroy_application(&app);
	allfree();
	return (0);
}
