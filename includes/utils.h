/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:10:26 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/02 15:29:55 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>

typedef struct	s_vec2
{
	float	x;
	float	y;
}	t_vec2;

void	vec2_add(t_vec2 *vec0, t_vec2 vec1);
t_vec2	vec2_add_copy(t_vec2 vec0, t_vec2 vec1);
void	vec2_add_n(t_vec2 *vec0, float n);
t_vec2	vec2_add_n_copy(t_vec2 vec0, float n);
void	vec2_sub(t_vec2 *vec0, t_vec2 vec1);
t_vec2	vec2_sub_copy(t_vec2 vec0, t_vec2 vec1);
void	vec2_sub_n(t_vec2 *vec0, float n);
t_vec2	vec2_sub_n_copy(t_vec2 vec0, float n);
void	vec2_mul(t_vec2 *vec0, t_vec2 vec1);
t_vec2	vec2_mul_copy(t_vec2 vec0, t_vec2 vec1);
void	vec2_mul_n(t_vec2 *vec0, float n);
t_vec2	vec2_mul_n_copy(t_vec2 vec0, float n);
float	deg_to_rad(int a);
int		fix_ang(int a);

#endif
