/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:39:53 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/08 10:28:46 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdint.h>
# include <stddef.h>
# include <player.h>
# include <utils.h>

# define FOV			80
# define CUBE_SIZE		64
# define WIDTH			1250
# define HEIGHT			720
# define DR				0.0174533

typedef struct	s_textures_files
{
	const char	*north;
	const char	*south;
	const char	*west;
	const char	*east;
}	t_textures_files;

typedef struct	s_textures
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_textures;

typedef struct	s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct	s_world
{
	t_color	ceiling;
	t_color	floor;
	uint8_t	**map;
	size_t	map_x_size;
	size_t	map_y_size;
}	t_world;

typedef struct s_platform
{
	void	*mlx;
	void	*win;
}	t_platform;

typedef struct	s_renderer
{
	t_textures	*textures;
	t_world		*world;
	t_platform	*plat;
}	t_renderer;

typedef struct s_ray
{
	t_vec2	pos;
	t_vec2	offset;
	t_vec2	line_pos;
	float	ang;
	float	distance;
	float	coang;
	float	lineoff;
	int		lineh;
	int		i;
}	t_ray;

t_renderer	*init_renderer(t_textures_files *textures, t_world *world);
void		render(t_renderer *renderer, t_player *player);
void		destroy_renderer(t_renderer *renderer);
void		draw_line(t_renderer *renderer, t_vec2 v0, t_vec2 v1, int color);
void		draw_vert_line(t_renderer *renderer, t_vec2 pos, int h, int color);
void		draw_rect(t_renderer *renderer, t_vec2 pos, t_vec2 dims, int color);
int			get_color(t_color color);

#endif
