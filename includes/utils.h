/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:10:26 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 08:35:15 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_vec2
{
	int	x;
	int	y;
}	t_vec2;

void	vec2_add(t_vec2 *vec0, t_vec2 vec1);
void	vec2_add_n(t_vec2 *vec0, int n);
void	vec2_sub(t_vec2 *vec0, t_vec2 vec1);
void	vec2_sub_n(t_vec2 *vec0, int n);
void	vec2_mul(t_vec2 *vec0, t_vec2 vec1);
void	vec2_mul_n(t_vec2 *vec0, int n);
float	deg_to_rad(int a);
int		fix_ang(int a);

#endif
