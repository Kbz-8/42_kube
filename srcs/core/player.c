/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:02:35 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/12 15:09:53 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player.h>
#include <renderer.h>
#include <utils.h>

void	init_player(t_player *player, t_world *world)
{
	player->pos.x = world->player_init_x * CUBE_SIZE + (CUBE_SIZE >> 1);
	player->pos.y = world->player_init_y * CUBE_SIZE + (CUBE_SIZE >> 1);
	player->angle = 0;
	if (world->player_orientation == 'N')
		player->angle = M_PI / 2;
	else if (world->player_orientation == 'S')
		player->angle = 1.5f * M_PI;
	else if (world->player_orientation == 'E')
		player->angle = 2 * M_PI;
	else if (world->player_orientation == 'W')
		player->angle = M_PI;
	player->left.x = -player->dir.y;
	player->left.y = player->dir.x;
}
