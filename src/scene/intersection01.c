/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:04:59 by darwin            #+#    #+#             */
/*   Updated: 2025/03/24 12:46:16 by kpedro           ###   ########.fr       */
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

t_pair	which_sphere(t_scene *rt, t_ray *ray)
{
	int		i;
	t_pair	closest;

	ft_bzero(&closest, sizeof(t_pair));
	i = 0;
	while (i < rt->nb.sphere)
	{
		if (sphere_intersection(&rt->sphere[i], ray) > 0)
		{
			closest.t = sphere_intersection(&rt->sphere[i], ray);
			closest.normal = sphere_normal(gen_point(closest.t, ray),
					&rt->sphere[i]);
			closest.color = rt->sphere[i].color;
			break ;
		}
		i++;
	}
	return (closest);
}

t_pair	which_plane(t_scene *rt, t_ray *ray)
{
	int		i;
	t_pair	closest;

	ft_bzero(&closest, sizeof(t_pair));
	i = 0;
	while (i < rt->nb.plane)
	{
		if (plane_intersection(&rt->plane[i], ray) > 0)
		{
			closest.t = plane_intersection(&rt->plane[i], ray);
			closest.normal = rt->plane->dir;
			closest.color = rt->plane[i].color;
			break ;
		}
		i++;
	}
	return (closest);
}

t_pair	which_cylinder(t_scene *rt, t_ray *ray)
{
	int		i;
	t_pair	closest;

	ft_bzero(&closest, sizeof(t_pair));
	i = 0;
	while (i < rt->nb.cylinder)
	{
		if (cylinder_intersection(&rt->cylinder[i], ray) > 0)
		{
			// printf("%f\n", cylinder_intersection(&rt->cylinder[i], ray));
			closest.t = cylinder_intersection(&rt->cylinder[i], ray);
			closest.normal = cylinder_normal(gen_point(closest.t, ray),
					&rt->cylinder[i]);
			closest.color = rt->cylinder[i].color;
			break ;
		}
		i++;
	}
	return (closest);
}
