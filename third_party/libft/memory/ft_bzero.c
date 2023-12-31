/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:58:30 by maldavid          #+#    #+#             */
/*   Updated: 2022/09/20 17:01:49 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, t_size n)
{
	t_uint8	*tmp;

	tmp = (t_uint8 *)ptr;
	while (n)
	{
		*tmp++ = 0;
		n--;
	}
}
