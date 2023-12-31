/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:37 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/31 21:23:37 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stddef.h>

typedef struct s_block
{
	void			*ptr;
	struct s_block	*next;
	size_t			size;
}	t_block;

void	*alloc(size_t size);
void	*realloc_but_not_the_std_lib(void *ptr, size_t size);
void	dealloc(void *ptr);
void	allfree(void);

#endif
