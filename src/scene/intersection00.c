/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darwin <darwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:31:46 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/11 18:06:38 by darwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

double	sphere_intersection(t_sphere *sphere, t_ray *ray)
{
	double	A;
	double	B;
	double	C;
	double	delta;
	double	roots[2];

	A = vector_dot(ray->direction, ray->direction);
	B = 2.0 * vector_dot(ray->direction, sub_vec(ray->origin,
				sphere->position));
	C = vector_dot(sub_vec(ray->origin, sphere->position), sub_vec(ray->origin,
				sphere->position)) - (sphere->radius * sphere->radius);
	delta = (B * B) - (4 * A * C);
	if (delta < 0)
		return (-1);
	roots[0] = (-B + sqrt(delta)) / (2 * A);
	roots[1] = (-B - sqrt(delta)) / (2 * A);
	if (roots[0] > 0 && roots[1] > 0)
		return (fmin(roots[0], roots[1]));
	else if (roots[0] > 0)
		return (roots[0]);
	else if (roots[1] > 0)
		return (roots[1]);
	return (-1);
}

double	plane_intersection(t_plane *plane, t_ray *ray)
{
	double	value1;
	double	value2;
	double	t;

	value1 = vector_dot(plane->normal_vector, ray->direction);
	if (value1 == 0)
		return (-1);
	value2 = vector_dot(plane->normal_vector, sub_vec(plane->position,
				ray->origin));
	t = value2 / value1;
	if (t < 0)
		return (-1);
	return (t);
}

double cylinder_sides_intersection(t_cylinder *cy, t_ray *ray)
{
	double	A;
	double	B;
	double	C;
	double	delta;
	double	roots[2];
	
	A = (ray->direction.x * ray->direction.x) + (ray->direction.z * ray->direction.z);
	B = 2 * (ray->direction.x * (ray->origin.x - cy->position.x) + 
			ray->direction.z * (ray->origin.z - cy->position.z));
	C =  ((ray->origin.x * ray->origin.x) + (ray->origin.z * ray->origin.z)) - 2 * 
			(ray->origin.x * cy->position.x) - 2 * (ray->origin.z * cy->position.z) + 
			(cy->position.x * cy->position.x) + (cy->position.z * cy->position.z) - (cy->radius * cy->radius);
	delta = (B * B) - (4 * A * C);
	if (delta < 0 || A == 0)
		return (-1);
	roots[0] = (-B + sqrt(delta)) / (2 * A);
	roots[1] = (-B - sqrt(delta)) / (2 * A);
	if (roots[0] > 0 && roots[1] > 0)
		return (fmin(roots[0], roots[1]));
	else if (roots[0] > 0)
		return (roots[0]);
	else if (roots[1] > 0)
		return (roots[1]);
	return (-1);
}

double cylinder_sides_heigth(double t, t_cylinder *cy, t_ray *ray)
{
	t_vector point;
	double	y_min;
	double	y_max;
	double	t[2];

	y_min = cy->normal_vector.y;
	y_max = y_min + cy->height;
	point.y = ray->origin.y + t * ray->direction.y;
	if (y_min <= point.y && point.y <= y_max)
		return (t);
	else
		return (-1);
}
