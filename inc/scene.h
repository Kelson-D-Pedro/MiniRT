/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:47:54 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 10:40:02 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"

# define HEIGHT 600
# define WIDTH 900
# define M_PI1 3.1415

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

typedef struct s_pair
{
	t_rgb_color			color;
	t_vector			normal;
	double				t;
	int					index;
	char				type;
}						t_pair;

typedef struct s_aabb
{
	t_vector			max;
	t_vector			min;
}						t_aabb;

typedef struct s_scene
{
	t_camera			camera;
	t_ambient_light		ambiente_light;
	t_light				light;
	t_sphere			*sphere;
	t_cylinder			*cylinder;
	t_plane				*plane;
	t_num_of_elements	nb;
	t_mlx				mini_lx;
	t_vector			right_3d;
	t_vector			up_3d;
	t_vector			left_inf_point;
	double				viewport_height;
	double				viewport_width;
	char				**map;
	t_pair				active_obj;
}						t_scene;

//
//------------------------------- T_PAIR FUNCTIONS
//

t_pair					which_sphere(t_scene *rt, t_ray *ray);
t_pair					which_plane(t_scene *rt, t_ray *ray);
t_pair					which_cylinder(t_scene *rt, t_ray *ray);
t_pair					intersect_objs(t_scene *rt, t_ray *ray);

//
//------------------------------- T_VECTOR FUNCTIONS
//

t_vector				gen_point(double t, t_ray *ray);
t_vector				sphere_normal(t_vector point, t_sphere *sphere);
t_vector				cylinder_normal(t_vector point, t_cylinder *cy);

//
//------------------------------- T_AMBIENT_LIGHT FUNCTIONS
//

t_rgb_color				force(t_scene *rt, t_ray *ray, t_pair *obj);

//
//------------------------------- T_SPHERE FUNCTIONS
//

t_aabb					sphere_box(t_sphere *sp);
t_aabb					cylinder_box(t_cylinder *cy);
int						intersect_box(t_aabb box, t_ray *ray);

//
//------------------------------- T_RAY FUNCTIONS
//

t_ray					send_rays(t_scene *rt, int x, int y);

//
//------------------------------- T_CYLINDER FUNCTIONS
//

//
//------------------------------- T_MLX FUNCTIONS
//

void					init_mlx_win(t_scene *rt);
void					init_mlx_image(t_scene *rt);
void					my_pixel_put(t_scene *rt, int x, int y, int color);
int						select_obj(int key, int x, int y, void *arg);
int						moves(int key, t_vector *pos, t_scene *rt,
							t_vector *dir);
int						hooks(int key, void *arg);
int						close_window(t_scene *rt);
int						handle_keypress(int keycode, t_scene *rt);

#endif
