/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:52 by maldavid          #+#    #+#             */
/*   Updated: 2023/07/31 21:24:11 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <stdlib.h>
#include <errors.h>
#include <libft.h>

static t_block	**get_blocks(void)
{
	static t_block	*head = NULL;

	return (&head);
}

void	*alloc(size_t size)
{
	t_block	*block;

	block = malloc(sizeof(t_block) + 1);
	if (block == NULL)
		report(FATAL_ERROR, E_MEMFAIL);
	block->next = *get_blocks();
	block->ptr = malloc(size + 1);
	block->size = size + 1;
	if (block->ptr == NULL)
		report(FATAL_ERROR, E_MEMFAIL);
	ft_memset(block->ptr, 0, size + 1);
	*get_blocks() = block;
	return (block->ptr);
}

void	*realloc_but_not_the_std_lib(void *ptr, size_t size)
{
	t_block	*buf;
	void	*tmp;

	buf = *get_blocks();
	while (buf != NULL)
	{
		if (buf->ptr == ptr)
		{
			tmp = malloc(size);
			if (tmp == NULL)
				report(FATAL_ERROR, E_MEMFAIL);
			ft_memcpy(tmp, ptr, buf->size);
			free(buf->ptr);
			buf->ptr = tmp;
			return (buf->ptr);
		}
		buf = buf->next;
	}
	return (NULL);
}

void	dealloc(void *ptr)
{
	t_block	*buf[2];

	buf[0] = *get_blocks();
	if (buf[0] == NULL)
		return ;
	if (buf[0]->ptr == ptr)
	{
		buf[1] = buf[0];
		*get_blocks() = buf[0]->next;
		free(buf[1]->ptr);
		free(buf[1]);
		return ;
	}
	while (buf[0]->next != NULL)
	{
		if (buf[0]->next->ptr == ptr)
		{
			buf[1] = buf[0]->next;
			buf[0]->next = buf[1]->next;
			free(buf[1]->ptr);
			free(buf[1]);
			return ;
		}
		buf[0] = buf[0]->next;
	}
}

void	allfree(void)
{
	t_block	*buf;
	t_block	*dbuf;

	buf = *get_blocks();
	while (buf != NULL)
	{
		dbuf = buf->next;
		free(buf->ptr);
		free(buf);
		buf = dbuf;
	}
}
