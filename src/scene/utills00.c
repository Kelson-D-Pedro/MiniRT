/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:35:41 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/23 18:48:20 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_aabb	sphere_box(t_sphere *sp)
{
	t_aabb	box;

	box.max.x = sp->pos.x + sp->radius;
	box.max.y = sp->pos.y + sp->radius;
	box.max.z = sp->pos.z + sp->radius;
	box.min.x = sp->pos.x - sp->radius;
	box.min.y = sp->pos.y - sp->radius;
	box.min.z = sp->pos.z - sp->radius;
	return (box);
}

t_aabb	cylinder_box(t_cylinder *cy)
{
	t_vector	top;
	t_vector	bottom;
	t_aabb		box;

	top = add_vec(cy->pos, scalar_mult(cy->dir, cy->height / 2));
	bottom = sub_vec(cy->pos, scalar_mult(cy->dir, cy->height / 2));
	box.max.x = fmax(top.x, bottom.x) + cy->radius;
	box.max.y = fmax(top.y, bottom.y) + cy->radius;
	box.max.z = fmax(top.z, bottom.z) + cy->radius;
	box.min.x = fmin(top.x, bottom.x) - cy->radius;
	box.min.y = fmin(top.y, bottom.y) - cy->radius;
	box.min.z = fmin(top.z, bottom.z) - cy->radius;
	return (box);
}

static void	swap(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	intersect_box(t_aabb box, t_ray *ray)
{
	double	tx[2];
	double	ty[2];
	double	tz[2];

	tx[0] = (box.min.x - ray->origin.x) / ray->dir.x;
	tx[1] = (box.max.x - ray->origin.x) / ray->dir.x;
	if (tx[0] > tx[1])
		swap(&tx[0], &tx[1]);
	ty[0] = (box.min.y - ray->origin.y) / ray->dir.y;
	ty[1] = (box.max.y - ray->origin.y) / ray->dir.y;
	if (ty[0] > ty[1])
		swap(&ty[0], &ty[1]);
	if (tx[0] > ty[1] || ty[0] > tx[1])
		return (0);
	if (ty[0] > tx[0])
		tx[0] = ty[0];
	if (ty[1] < tx[1])
		tx[1] = ty[1];
	tz[0] = (box.min.z - ray->origin.z) / ray->dir.z;
	tz[1] = (box.max.z - ray->origin.z) / ray->dir.z;
	if (tz[0] > tz[1])
		swap(&tz[0], &tz[1]);
	if (tx[0] > tz[1] || tz[0] > tx[1])
		return (0);
	return (1);
}
