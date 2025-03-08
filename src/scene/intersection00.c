/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:31:46 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/07 13:06:59 by kpedro           ###   ########.fr       */
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
