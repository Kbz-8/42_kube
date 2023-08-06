/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:39:53 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/06 20:55:48 by vvaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdint.h>
# include <player.h>
# include <utils.h>

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
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_world
{
	t_color	ceiling;
	t_color	floor;
	uint8_t	**map;
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

t_renderer	*init_renderer(t_textures_files *textures, t_world *world);
void		render(t_renderer *renderer, t_player *player);
void		destroy_renderer(t_renderer *renderer);
void		draw_line(t_renderer *renderer, t_vec2 v0, t_vec2 v1, int color);

#endif
