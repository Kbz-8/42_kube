/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:58:55 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 03:21:20 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLICATION_H
# define APPLICATION_H

# include <renderer.h>

typedef struct s_application
{
	t_renderer	*renderer;
}	t_application;

void	init_application(t_application *app);
void	run(t_application *app);
int		update(t_application *app);
void	destroy_application(t_application *app);

#endif
