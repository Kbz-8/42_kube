/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:02:35 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/08 08:04:04 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player.h>

void	init_player(t_player *player)
{
	player->pos.x = 150;
	player->pos.y = 400;
	player->dir.x = 1;
	player->dir.y = 1;
	player->left.x = -player->dir.y;
	player->left.y = player->dir.x;
	player->angle = 0;
}
