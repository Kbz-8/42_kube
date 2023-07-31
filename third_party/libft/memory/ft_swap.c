/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:42:35 by maldavid          #+#    #+#             */
/*   Updated: 2022/10/03 15:55:53 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b)
{
	t_uint8	*p_a;
	t_uint8	*p_b;

	p_a = (t_uint8 *)a;
	p_b = (t_uint8 *)b;
	if (*p_a == *p_b)
		return ;
	*p_a ^= *p_b;
	*p_b ^= *p_a;
	*p_a ^= *p_b;
}
