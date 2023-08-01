/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:39:53 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/01 07:43:05 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdint.h>

typedef struct	s_textures_files
{
	const char	*north;
	const char	*south;
	const char	*west;
	const char	*est;
}	t_textures_files;

typedef struct	s_textures
{
	void	*north;
	void	*south;
	void	*west;
	void	*est;
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
void		render(t_renderer *renderer);
void		destroy_renderer(t_renderer *renderer);

#endif
