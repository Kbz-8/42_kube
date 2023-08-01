/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:04:24 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 10:25:33 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <utils.h>

typedef struct	s_player
{
	t_vec2	pos;
	t_vec2	dir;
}	t_player;

void	init_player(t_player *player);

#endif
