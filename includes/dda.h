/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:13:26 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 10:41:09 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include <utils.h>
# include <stdbool.h>
# include <renderer.h>

typedef struct s_dda
{
	t_vec2	distance;
	t_vec2	vert;
	t_vec2	hori;
	t_vec2	map;
	float	tan;
	int		i;
	bool	run;
	bool	horizontal;
}	t_dda;

void	dda_algorithm(t_renderer *r, t_player *player, t_ray *ray, t_dda *dda);

#endif
