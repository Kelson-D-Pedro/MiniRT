/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:31:46 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/24 12:44:42 by kpedro           ###   ########.fr       */
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
	value2 = vector_dot(plane->dir, sub_vec(plane->dir, ray->origin));
	t = value2 / value1;
	if (t < 0)
		return (-1);
	return (t);
}

double	cylinder_sides_intersection(t_cylinder *cy, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	roots[2];

	a = (ray->dir.x * ray->dir.x) + (ray->dir.z * ray->dir.z);
	b = 2 * (ray->dir.x * (ray->origin.x - cy->pos.x) + ray->dir.z
			* (ray->origin.z - cy->pos.z));
	c = ((ray->origin.x * ray->origin.x) + (ray->origin.z * ray->origin.z)) - 2
		* (ray->origin.x * cy->pos.x) - 2 * (ray->origin.z * cy->pos.z)
		+ (cy->pos.x * cy->pos.x) + (cy->pos.z * cy->pos.z) - (cy->radius
			* cy->radius);
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

double	validate_cylinder_sides_heigth(double t, t_cylinder *cy, t_ray *ray)
{
	t_vector	point;
	double		y_min;
	double		y_max;

	y_min = cy->pos.y;
	y_max = y_min + cy->height;
	point.y = ray->origin.y + t * ray->dir.y;
	if (y_min <= point.y && point.y <= y_max)
		return (t);
	else
		return (-1);
}

double	cylinder_intersection(t_cylinder *cy, t_ray *ray)
{
	double	roots[3];

	roots[0] = cylinder_sides_intersection(cy, ray);
	roots[1] = cylinder_cover_intersection(cy, ray);
	roots[2] = validate_cylinder_sides_heigth(roots[0], cy, ray);
	if (roots[1] > 0 && roots[2] > 0)
		return (fmin(roots[1], roots[2]));
	else if (roots[1] > 0)
		return (roots[1]);
	else if (roots[2] > 0)
		return (roots[2]);
	return (-1);
}
