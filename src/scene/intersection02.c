/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:54:47 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 10:03:06 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

double	validate_cylinder_sides_heigth(double t, t_cylinder *cy, t_ray *ray)
{
	t_vector	point;
	double		proj_len;

	if (t < 0)
		return (-1);
	point = gen_point(t, ray);
	proj_len = vector_dot(sub_vec(point, cy->pos), cy->dir);
	if (proj_len >= -cy->height / 2 && proj_len <= cy->height / 2)
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

t_pair	intersect_objs(t_scene *rt, t_ray *ray)
{
	t_pair	closest;
	t_pair	sp;
	t_pair	cy;
	t_pair	pl;

	closest.t = -1;
	sp = which_sphere(rt, ray);
	cy = which_cylinder(rt, ray);
	pl = which_plane(rt, ray);
	if (sp.t > 0 && (closest.t == -1 || sp.t < closest.t))
		closest = sp;
	if (pl.t > 0 && (closest.t == -1 || pl.t < closest.t))
		closest = pl;
	if (cy.t > 0 && (closest.t == -1 || cy.t < closest.t))
		closest = cy;
	return (closest);
}
