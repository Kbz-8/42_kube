/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:08:41 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 19:08:35 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float deg_to_rad(float a)
{
	return (a * M_PI / 180);
}

float fix_ang(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
   	return (a);
}

float	ft_fabs(float a)
{
	long	i;

	i = *(long *)&a;
	i &= ~(1u << 31);
	return *(float *)&i;
}

void	fswap(float *a, float *b)
{
	float tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
