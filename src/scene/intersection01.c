/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:04:59 by darwin            #+#    #+#             */
/*   Updated: 2025/03/13 12:41:02 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static double	cover_intersection_aux(double *t, t_ray *ray, t_cylinder *cy)
{
	int		i;
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
			x = ray->origin.x + t[i] * ray->dir.x;
			z = ray->origin.z + t[i] * ray->dir.z;
			value = ((x - cy->pos.x) * (x - cy->pos.x)) + ((z - cy->pos.z) * (z
						- cy->pos.z));
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

	y_min = cy->pos.y;
	y_max = y_min + cy->height;
	if (ray->dir.y == 0)
		return (-1);
	t[0] = (y_min - ray->origin.y) / ray->dir.y;
	t[1] = (y_max - ray->origin.y) / ray->dir.y;
	return (cover_intersection_aux(t, ray, cy));
}

t_pair	which_sphere(t_elements *rt, t_ray *ray)
{
	int		i;
	t_pair	*pairs;
	t_pair	closest;

	i = 0;
	if (rt->nb.sphere <= 0)
		return ((t_pair){-1, -1});
	pairs = malloc(sizeof(t_pair) * rt->nb.sphere);
	while (i < rt->nb.sphere)
	{
		pairs[i].index = i;
		pairs[i].t = sphere_intersection(&rt->sphere[i++], ray);
	}
	i = 0;
	closest = (t_pair){-1, INFINITY};
	while (i < (rt->nb.sphere))
	{
		if (pairs[i].t > EPSILON && pairs[i].t < closest.t)
			closest = pairs[i];
		i++;
	}
	free(pairs);
	return (closest);
}

t_pair	which_plane(t_elements *rt, t_ray *ray)
{
	int		i;
	t_pair	*pairs;
	t_pair	closest;

	i = 0;
	if (rt->nb.plane <= 0)
		return ((t_pair){-1, -1});
	pairs = malloc(sizeof(t_pair) * rt->nb.plane);
	while (i < rt->nb.plane)
	{
		pairs[i].index = i;
		pairs[i].t = plane_intersection(&rt->plane[i++], ray);
	}
	i = 0;
	closest = (t_pair){-1, INFINITY};
	while (i < (rt->nb.plane))
	{
		if (pairs[i].t > EPSILON && pairs[i].t < closest.t)
			closest = pairs[i];
		i++;
	}
	free(pairs);
	return (closest);
}

t_pair	which_cylinder(t_elements *rt, t_ray *ray)
{
	int		i;
	t_pair	*pairs;
	t_pair	closest;

	i = 0;
	if (rt->nb.cylinder <= 0)
		return ((t_pair){-1, -1});
	pairs = malloc(sizeof(t_pair) * rt->nb.cylinder);
	while (i < rt->nb.cylinder)
	{
		pairs[i].index = i;
		pairs[i].t = cylinder_intersection(&rt->cylinder[i++], ray);
	}
	i = 0;
	closest = (t_pair){-1, INFINITY};
	while (i < (rt->nb.cylinder))
	{
		if (pairs[i].t > EPSILON && pairs[i].t < closest.t)
			closest = pairs[i];
		i++;
	}
	free(pairs);
	return (closest);
}
