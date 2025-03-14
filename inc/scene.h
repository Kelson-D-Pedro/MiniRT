/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:47:54 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/13 14:40:30 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"

//
//-------------------------------STRUCTURES
//

typedef struct s_rgb_color
{
	int					red;
	int					green;
	int					blue;
}						t_rgb_color;

typedef struct s_ambient_light
{
	double				intensity;
	t_rgb_color			color;

}						t_ambient_light;

typedef struct s_camera
{
	t_vector			pos;
	t_vector			dir;
	double				fov;
}						t_camera;

typedef struct s_light
{
	t_vector			pos;
	double				brightness;
	t_rgb_color			color;
}						t_light;

typedef struct s_sphere
{
	t_vector			pos;
	double				diameter;
	double				radius;
	t_rgb_color			color;
}						t_sphere;

typedef struct s_plane
{
	t_vector			pos;
	t_vector			dir;
	t_rgb_color			color;
}						t_plane;

typedef struct s_cylinder
{
	t_vector			pos;
	t_vector			dir;
	double				height;
	double				diameter;
	double				radius;
	t_rgb_color			color;
}						t_cylinder;

typedef struct s_num_of_elements
{
	int					camera;
	int					ambient_light;
	int					light;
	int					sphere;
	int					cylinder;
	int					plane;
}						t_num_of_elements;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*addr;
	int					***map;
	int					bpp;
	int					line_length;
	int					endian;

}						t_mlx;

typedef struct s_ray
{
	t_vector			origin;
	t_vector			dir;
}						t_ray;

typedef struct s_elements
{
	t_camera			camera;
	t_ambient_light		ambiente_light;
	t_light				light;
	t_sphere			*sphere;
	t_cylinder			*cylinder;
	t_plane				*plane;
	t_num_of_elements	nb;
	t_mlx				mini_lx;
	char				**map;
}						t_elements;

typedef struct s_pair
{
	int					index;
	double				t;
}						t_pair;

//
//------------------------------- T_PAIR FUNCTIONS
//

t_pair					which_sphere(t_elements *rt, t_ray *ray);
t_pair					which_plane(t_elements *rt, t_ray *ray);
t_pair					which_cylinder(t_elements *rt, t_ray *ray);

//
//------------------------------- T_VECTOR FUNCTIONS
//

t_vector				gen_point(double t, t_ray *ray);

//
//------------------------------- T_AMBIENT_LIGHT FUNCTIONS
//

//
//------------------------------- T_SPHERE FUNCTIONS
//

//
//------------------------------- T_PLANE FUNCTIONS
//

//
//------------------------------- T_CYLINDER FUNCTIONS
//

//
//------------------------------- T_MLX FUNCTIONS
//

void					init_mlx_win(t_elements *rt);

#endif
