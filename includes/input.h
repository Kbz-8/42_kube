/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:13:09 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 15:18:21 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <application.h>

# define KEY_W 0
# define KEY_S 1
# define KEY_Q 2
# define KEY_D 3
# define KEY_LEFT  4
# define KEY_RIGHT 5

int	keydown_hook(int key, t_application *app);
int	keyup_hook(int key, t_application *app);
int	window_hook(int event, t_application *app);

#endif
