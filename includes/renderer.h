/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:39:53 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/09 11:16:26 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdint.h>
# include <stddef.h>
# include <player.h>
# include <utils.h>

# define FOV					70
# define CUBE_SIZE				64
# define TEXTURE_SIZE			128
# define WIDTH					1250
# define HEIGHT					720
# define DEG_TO_RAD				0.0174533

typedef struct	s_dda	t_dda;

typedef struct	s_textures_files
{
	const char	*north;
	const char	*south;
	const char	*west;
	const char	*east;
}	t_textures_files;

typedef struct	s_texture
{
	void	*img;
	int		w;
	int		h;
}	t_texture;

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
	t_texture	tex[4];
	t_world		*world;
	t_platform	*plat;
}	t_renderer;

typedef struct s_ray
{
	t_vec2	line_pos;
	t_vec2	offset;
	t_vec2	pos;
	t_vec2	tex;
	float	distance;
	float	line_off;
	float	texy_off;
	float	tex_step;
	float	ang;
	int		i;
	int		line_h;
}	t_ray;

t_renderer	*init_renderer(t_textures_files *textures, t_world *world);
void		render(t_renderer *renderer, t_player *player);
void		destroy_renderer(t_renderer *renderer);
void		draw_line(t_renderer *renderer, t_vec2 v0, t_vec2 v1, int color);
void		draw_vert_line(t_renderer *renderer, t_vec2 pos, int h, int color);
void		draw_rect(t_renderer *renderer, t_vec2 pos, t_vec2 dims, int color);
int			get_color(t_color color);
void		depth_lightning(uint8_t color[4], t_ray *ray, t_dda *dda);

#endif
