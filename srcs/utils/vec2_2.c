/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:37:32 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 15:30:06 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_vec2	vec2_sub_copy(t_vec2 vec0, t_vec2 vec1)
{
	vec0.x -= vec1.x;
	vec0.y -= vec1.y;
	return (vec0);
}

void	vec2_mul(t_vec2 *vec0, t_vec2 vec1)
{
	vec0->x *= vec1.x;
	vec0->y *= vec1.y;
}

void	vec2_mul_n(t_vec2 *vec0, float n)
{
	vec0->x *= n;
	vec0->y *= n;
}

t_vec2	vec2_mul_copy(t_vec2 vec0, t_vec2 vec1)
{
	vec0.x *= vec1.x;
	vec0.y *= vec1.y;
	return (vec0);
}

t_vec2	vec2_mul_n_copy(t_vec2 vec0, float n)
{
	vec0.x *= n;
	vec0.y *= n;
	return (vec0);
}
