/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:36:09 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/02 15:29:40 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_vector	gen_point(double t, t_ray *ray)
{
	t_vector	point;

	point.x = ray->origin.x + t * ray->dir.x;
	point.y = ray->origin.y + t * ray->dir.y;
	point.z = ray->origin.z + t * ray->dir.z;
	return (point);
}

t_vector	sphere_normal(t_vector point, t_sphere *sphere)
{
	t_vector	aux;

	aux = sub_vec(point, sphere->pos);
	vector_normalize(&aux);
	return (aux);
}

t_vector	cylinder_normal(t_vector point, t_cylinder *cy)
{
	t_vector	normal;
	double		y_top;
	double		y_bottom;

	y_top = cy->pos.y + (cy->height / 2);
	y_bottom = cy->pos.y - (cy->height / 2);
	if (fabs(point.y - y_top) < EPSILON)
		return ((t_vector){0, 1, 0});
	else if (fabs(point.y - y_bottom) < EPSILON)
		return ((t_vector){0, -1, 0});
	else if (y_bottom <= point.y && point.y <= y_top)
	{
		normal.x = point.x - cy->pos.x;
		normal.y = 0;
		normal.z = point.z - cy->pos.z;
		vector_normalize(&normal);
		return (normal);
	}
	return ((t_vector){0, 0, 0});
}

static int	convert_color(t_rgb_color color)
{
	return (color.red << 16 | color.green << 8 | color.blue);
}

void	put_map(t_scene *rt)
{
	int		x;
	int		y;
	t_ray	rays;
	t_pair	objs;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			rays = send_rays(rt, x, y);
			objs = intersect_objs(rt, &rays);
			if (objs.t > 0)
				my_pixel_put(rt, x, y, convert_color(force(rt, &rays, &objs)));
			y++;
		}
		x++;
	}
}
