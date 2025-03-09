/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darwin <darwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:31:46 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/09 19:36:50 by darwin           ###   ########.fr       */
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
		return (MIN);
	roots[0] = (-B + sqrt(delta)) / (2 * A);
	roots[1] = (-B - sqrt(delta)) / (2 * A);
	if (roots[0] > 0 && roots[1] > 0)
		return (fmin(roots[0], roots[1]));
	else if (roots[0] > 0)
		return (roots[0]);
	else if (roots[1] > 0)
		return (roots[1]);
	return (MIN);
}

double	plane_intersection(t_plane *plane, t_ray *ray)
{
	double	value1;
	double	value2;
	double	t;

	value1 = vector_dot(plane->normal_vector, ray->direction);
	if (value1 == 0)
		return (MIN);
	value2 = vector_dot(plane->normal_vector, sub_vec(plane->position,
				ray->origin));
	t = value2 / value1;
	if (t < 0)
		return (MIN);
	return (t);
}

double cylinder_sides_intersection(t_cylinder *cylinder, t_ray *ray)
{
	double	A;
	double	B;
	double	C;
	double	delta;
	double	roots[2];
	
	A = (ray->direction.x * ray->direction.x) + (ray->direction.z * ray->direction.z);
	B = 2 * (ray->direction.x * (ray->origin.x - cylinder->position.x) + 
			ray->direction.z * (ray->origin.z - cylinder->position.z));
	C =  ((ray->origin.x * ray->origin.x) + (ray->origin.z * ray->origin.z)) - 2 * 
			(ray->origin.x * cylinder->position.x) - 2 * (ray->origin.z * cylinder->position.z) + 
			(cylinder->position.x * cylinder->position.x) + (cylinder->position.z * cylinder->position.z) - (cylinder->radius * cylinder->radius);
	delta = (B * B) - (4 * A * C);
	if (delta < 0)
		return (MIN);
	roots[0] = (-B + sqrt(delta)) / (2 * A);
	roots[1] = (-B - sqrt(delta)) / (2 * A);
	if (roots[0] > 0 && roots[1] > 0)
		return (fmin(roots[0], roots[1]));
	else if (roots[0] > 0)
		return (roots[0]);
	else if (roots[1] > 0)
		return (roots[1]);
	return (MIN);
}
