/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:05:08 by vvaas             #+#    #+#             */
/*   Updated: 2023/07/31 22:44:28 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_parse
{
	int	N_textures;
	int	E_textures;
	int	W_textures;
	int	S_textures;
	int	F_color;
	int	S_color;
}	t_parse;

void	parse(int ac, char **av);

#endif