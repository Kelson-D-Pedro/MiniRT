/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darwin <darwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:31:46 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/09 23:57:46 by darwin           ###   ########.fr       */
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

static double	cover_intersection_aux(double *t, t_ray *ray, t_cylinder *cy)
{
	int i;
	double	value;
	double	aux;
	double	x;
	double	z;

	i = 0;
	value = 0;
	aux = -1;
	while (i < 2)
	{
		if (t[i] > 0)
		{
			x = ray->origin.x + t[i] * ray->direction.x;
			z = ray->origin.z + t[i] * ray->direction.z;
			value = ((x - cy->position.x) * (x - cy->position.x)) + ((z - cy->position.z) * (z - cy->position.z));
			if (value <= cy->radius * cy->radius)
				if (aux == -1 || t[i] < aux)
					aux = t[i]; 
		}
		i++;
	}
	return (aux);
}

double	cylinder_cover_intersection(t_cylinder *cy, t_ray *ray)
{
	double	y_min;
	double	y_max;
	double	t[2];

	y_min = cy->position.y;
	y_max = y_min + cy->height;
	if (ray->direction.y == 0)
		return (-1);
	t[0] = (y_min - ray->origin.y) / ray->direction.y;
	t[1] = (y_max - ray->origin.y) / ray->direction.y;
}
