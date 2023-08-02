/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:34:49 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 15:30:10 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_vec2	vec2_add_n_copy(t_vec2 vec0, float n)
{
	vec0.x += n;
	vec0.y += n;
	return (vec0);
}

t_vec2	vec2_sub_n_copy(t_vec2 vec0, float n)
{
	vec0.x -= n;
	vec0.y -= n;
	return (vec0);
}
