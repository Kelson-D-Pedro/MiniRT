/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darwin <darwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:48:06 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/09 22:08:49 by darwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
//# include "../minilibx/mlx.h"
# include "scene.h"
# include "vector.h"

//
//------------------------------- INT FUNCTIONS
//

int		verify_file_extension(char *file_name);
int		verify_cap_elements(t_elements *rt);
int		verify_others_elements(char *file_name);
int		verify_file_stuffs(char *file_name, t_elements *rt);
int		verify_color(char *str1, int i);
int		verify_vector_values(char *str);
int		verify_normalized_vector(char *str);
int		verify_rt_file(t_elements *rt);
int		verify_elements(char **mat);
int		verify_ambient_light(char **mat);
int		verify_camera(char **mat);
int		verify_light(char **mat);
int		verify_sphere(char **mat);
int		verify_plane(char **mat);
int		verify_cylinder(char **mat);
int		its_alright_to_start(t_elements *rt, char **argv, int argc);

//
//------------------------------- DOUBLE FUNCTIONS
//

double	sphere_intersection(t_sphere *sphere, t_ray *ray);
double	plane_intersection(t_plane *plane, t_ray *ray);
double cylinder_sides_intersection(t_cylinder *cy, t_ray *ray);
double cylinder_sides_heigth(double t, t_cylinder *cy, t_ray *ray);
double	cylinder_cover_intersection(t_cylinder *cy, t_ray *ray);

//
//------------------------------- VOID FUNCTIONS
//

void	get_elements_quantity(t_num_of_elements *element, char *str);
void	fill_ambient_light(t_elements *rt, char **mat);
void	fill_camera(t_elements *rt, char **mat);
void	fill_light(t_elements *rt, char **mat);
void	fill_sphere(t_elements *rt, char **mat);
void	fill_plane(t_elements *rt, char **mat);
void	fill_cylinder(t_elements *rt, char **mat);
void	fill_elements(t_elements *rt);
void	choice_who_fill(t_elements *rt, char **mat);
void	normalize(t_elements *rt);

//
//------------------------------- CHAR FUNCTIONS
//

char	**get_map(char *file_name);

//
//------------------------------- T_ELEMENTS FUNCTIONS
//

#endif