/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:05:08 by vvaas             #+#    #+#             */
/*   Updated: 2023/08/09 17:23:18 by vvaas            ###   ########.fr       */
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

//-------------FILE MANIPULATION-----------

char	*fetch_line(char **file, char *target);
char	*fetch_path(char *line);
char	**get_file(char **av);
bool	check_file(char **file);

//-------------PARSING-----------
bool	is_map_character(char c);
bool	is_a_map(char **file);

//-------------TEXTURE PARSING-----------
bool	is_texture_name(char *str);
void	get_colors(t_color *floor, t_color *ceiling, char **file);

//-------------UTILS-----------
char	*jump_space(char *path);
int		ft_charcount(char *str, char character);
uint8_t	**convert_map(char **file, size_t *size_x, size_t *size_y);
uint8_t	**get_map(char **file, size_t *size_x, size_t *size_y);
char	get_last_char(char *line);
int		get_max_len(uint8_t **map);
bool	contain_invalid_chars(char **file);
bool	is_dir_char(char c);

#endif
