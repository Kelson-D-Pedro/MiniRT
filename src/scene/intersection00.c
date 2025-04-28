/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:31:46 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 10:03:09 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

double	sphere_intersection(t_sphere *sphere, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	roots[2];

	a = vector_dot(ray->dir, ray->dir);
	b = 2.0 * vector_dot(ray->dir, sub_vec(ray->origin, sphere->pos));
	c = vector_dot(sub_vec(ray->origin, sphere->pos), sub_vec(ray->origin,
				sphere->pos)) - (sphere->radius * sphere->radius);
	delta = (b * b) - (4 * a * c);
	if (delta < 0 || a == 0)
		return (-1);
	roots[0] = (-b + sqrt(delta)) / (2 * a);
	roots[1] = (-b - sqrt(delta)) / (2 * a);
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

	value1 = vector_dot(plane->dir, ray->dir);
	if (value1 == 0)
		return (-1);
	value2 = vector_dot(plane->dir, sub_vec(plane->pos, ray->origin));
	t = value2 / value1;
	if (t < 0)
		return (-1);
	return (t);
}

static int	solve_quad_eq(t_ray *ray, t_cylinder *cy, double roots[2])
{
	double		factors[3];
	double		delta;
	t_vector	perp_d;
	t_vector	perp_m;
	t_vector	m;

	m = sub_vec(ray->origin, cy->pos);
	perp_d = sub_vec(ray->dir, scalar_mult(cy->dir, vector_dot(ray->dir,
					cy->dir)));
	perp_m = sub_vec(m, scalar_mult(cy->dir, vector_dot(m, cy->dir)));
	factors[0] = vector_dot(perp_d, perp_d);
	factors[1] = 2 * vector_dot(perp_m, perp_d);
	factors[2] = vector_dot(perp_m, perp_m) - (cy->radius * cy->radius);
	delta = (factors[1] * factors[1]) - (4 * factors[0] * factors[2]);
	if (delta < 0 || factors[0] == 0)
		return (0);
	roots[0] = (-factors[1] + sqrt(delta)) / (2 * factors[0]);
	roots[1] = (-factors[1] - sqrt(delta)) / (2 * factors[0]);
	return (1);
}

double	cylinder_sides_intersection(t_cylinder *cy, t_ray *ray)
{
	double	roots[2];

	if (!solve_quad_eq(ray, cy, roots))
		return (-1);
	if (roots[0] > 0 && roots[1] > 0)
		return (fmin(roots[0], roots[1]));
	else if (roots[0] > 0)
		return (roots[0]);
	else if (roots[1] > 0)
		return (roots[1]);
	return (-1);
}
