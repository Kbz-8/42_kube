/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:08:41 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 02:44:19 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <utils.h>

float fix_ang(float a)
{
	if (a < 0)
		a += 2 * M_PI;
	if (a > 2 * M_PI)
		a -= 2 * M_PI;
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

float	dist(t_vec2 a, t_vec2 b)
{
	return (sqrt(powf(b.x - a.x, 2) + powf(b.y - a.y, 2)));
}

void	reverse_array(uint8_t arr[], int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
    {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
		i++;
    }
}
