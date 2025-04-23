/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:04:59 by darwin            #+#    #+#             */
/*   Updated: 2025/04/16 08:45:10 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static double	cover_intersection_aux(double *t, t_ray *ray, t_cylinder *cy, t_vector *covers)
{
    t_vector    point;
	int         i;
    double      t_min;
	double      dist;

	i = 0;
    t_min = -1;
	while (i < 2)
	{
		if (t[i] > EPSILON)
		{
            point = gen_point(t[i], ray);
            dist = vector_magnitude(sub_vec(point, covers[i]));
            if (dist <= cy->radius)
            {
                if (t_min < 0 || t[i] < t_min)
                    t_min = t[i];
            }
		}
		i++;
	}
    return (t_min);
}

double	cylinder_cover_intersection(t_cylinder *cy, t_ray *ray)
{
	t_vector    covers[2];
	double	t[2];
    
	if (fabs(vector_dot(ray->dir, cy->dir)) < EPSILON)
		return (-1);
	covers[0] = add_vec(cy->pos, scalar_mult(cy->dir, cy->height / 2));
    covers[1] = sub_vec(cy->pos, scalar_mult(cy->dir, cy->height / 2));
	t[0] = vector_dot(sub_vec(covers[0], ray->origin), cy->dir) / vector_dot(ray->dir, cy->dir);
	t[1] = vector_dot(sub_vec(covers[1], ray->origin), cy->dir) / vector_dot(ray->dir, cy->dir);
	return (cover_intersection_aux(t, ray, cy, covers));
}

t_pair which_sphere(t_scene *rt, t_ray *ray)
{
    int     i;
    t_pair  closest;
    double  t;

    ft_bzero(&closest, sizeof(t_pair));
    closest.t = INFINITY;
    i = 0;
    while (i < rt->nb.sphere)
    {
        t = sphere_intersection(&rt->sphere[i], ray);
        if (t > 0 && t < closest.t)
        {
            closest.t = t;
            closest.normal = sphere_normal(gen_point(t, ray), &rt->sphere[i]);
            closest.color = rt->sphere[i].color;
            closest.index = i;
            closest.type = 's';
        }
        i++;
    }
    return (closest);
}

t_pair which_plane(t_scene *rt, t_ray *ray)
{
    int     i;
    t_pair  closest;
    double  t;

    ft_bzero(&closest, sizeof(t_pair));
    closest.t = INFINITY;
    i = 0;
    while (i < rt->nb.plane)
    {
        t = plane_intersection(&rt->plane[i], ray);
        if (t > 0 && t < closest.t)
        {
            closest.t = t;
            closest.normal = rt->plane[i].dir;
            closest.color = rt->plane[i].color;
            closest.index = i;
            closest.type = 'p';
        }
        i++;
    }
    return (closest);
}

t_pair which_cylinder(t_scene *rt, t_ray *ray)
{
    int     i;
    t_pair  closest;
    double  t;

    ft_bzero(&closest, sizeof(t_pair));
    closest.t = INFINITY;
    i = 0;
    while (i < rt->nb.cylinder)
    {
        t = cylinder_intersection(&rt->cylinder[i], ray);
        if (t > 0 && t < closest.t)
        {
            closest.t = t;
            closest.normal = cylinder_normal(gen_point(t, ray), &rt->cylinder[i]);
            closest.color = rt->cylinder[i].color;
            closest.index = i;
            closest.type = 'c';
        }
        i++;
    }
    return (closest);
}
