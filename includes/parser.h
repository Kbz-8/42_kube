/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:05:08 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/07 03:13:02 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <renderer.h>
# include <stdbool.h>

typedef struct s_parse
{
	int	N_textures;
	int	E_textures;
	int	W_textures;
	int	S_textures;
	int	F_color;
	int	C_color;
}	t_parse;

void				parse(int ac, char **av);
t_textures_files	*get_textures_path(char **file);
t_world				*create_world(char **file);
char				**get_file(char **av);
bool				check_file(char **file);
char				*fetch_line(char **file, char *target);
char				*fetch_path(char *line);
char				*jump_space(char *path);
bool				is_texture_name(char *str);
bool				is_a_map(char **file);

#endif
