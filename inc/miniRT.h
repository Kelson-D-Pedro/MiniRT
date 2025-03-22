/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:48:06 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/18 14:23:59 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "scene.h"
# include "vector.h"

//
//------------------------------- INT FUNCTIONS
//

int		verify_file_extension(char *file_name);
int		verify_cap_elements(t_scene *rt);
int		verify_others_elements(char *file_name);
int		verify_file_stuffs(char *file_name, t_scene *rt);
int		verify_color(char *str1, int i);
int		verify_vector_values(char *str);
int		verify_normalized_vector(char *str);
int		verify_rt_file(t_scene *rt);
int		verify_elements(char **mat);
int		verify_ambient_light(char **mat);
int		verify_camera(char **mat);
int		verify_light(char **mat);
int		verify_sphere(char **mat);
int		verify_plane(char **mat);
int		verify_cylinder(char **mat);
int		its_alright_to_start(t_scene *rt, char **argv, int argc);

//
//------------------------------- DOUBLE FUNCTIONS
//

double	sphere_intersection(t_sphere *sphere, t_ray *ray);
double	plane_intersection(t_plane *plane, t_ray *ray);
double	cylinder_intersection(t_cylinder *cy, t_ray *ray);
double	cylinder_sides_intersection(t_cylinder *cy, t_ray *ray);
double	validate_cylinder_sides_heigth(double t, t_cylinder *cy, t_ray *ray);
double	cylinder_cover_intersection(t_cylinder *cy, t_ray *ray);

//
//------------------------------- VOID FUNCTIONS
//

void	get_scene_quantity(t_num_of_elements *element, char *str);
void	fill_ambient_light(t_scene *rt, char **mat);
void	fill_camera(t_scene *rt, char **mat);
void	fill_light(t_scene *rt, char **mat);
void	fill_sphere(t_scene *rt, char **mat);
void	fill_plane(t_scene *rt, char **mat);
void	fill_cylinder(t_scene *rt, char **mat);
void	fill_elements(t_scene *rt);
void	choice_who_fill(t_scene *rt, char **mat);
void	normalize(t_scene *rt);
void	put_map(t_scene *rt);
void	init_3d_camera(t_scene *rt);

//
//------------------------------- CHAR FUNCTIONS
//

char	**get_map(char *file_name);

//
//------------------------------- T_SCENE FUNCTIONS
//

#endif