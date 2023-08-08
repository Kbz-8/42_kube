/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 07:22:14 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/07 07:22:58 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	vec2_div(t_vec2 *vec0, t_vec2 vec1)
{
	vec0->x /= vec1.x;
	vec0->y /= vec1.y;
}

void	vec2_div_n(t_vec2 *vec0, float n)
{
	vec0->x /= n;
	vec0->y /= n;
}

t_vec2	vec2_div_copy(t_vec2 vec0, t_vec2 vec1)
{
	vec0.x /= vec1.x;
	vec0.y /= vec1.y;
	return (vec0);
}

t_vec2	vec2_div_n_copy(t_vec2 vec0, float n)
{
	vec0.x /= n;
	vec0.y /= n;
	return (vec0);
}
