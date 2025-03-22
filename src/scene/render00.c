/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:36:09 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/18 16:23:55 by kpedro           ###   ########.fr       */
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
	t_vector	normal;
	t_vector	aux;
	double		len;

	aux = sub_vec(point, sphere->pos);
	len = vector_magnitude(aux);
	if (len == 0)
		return ((t_vector){1, 0, 0});
	normal.x = aux.x / len;
	normal.y = aux.y / len;
	normal.z = aux.z / len;
	return (normal);
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

/*static int	convert_color(t_rgb_color color)
{
	return (color.red << 16 | color.green << 8 | color.blue);
}*/

void	put_map(t_scene *rt)
{
	int		x;
	int		y;
	t_ray	rays;
	t_pair	pair;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			rays = send_rays(rt, x, y);
			pair = which_sphere(rt, &rays);
			if (pair.t > 0)
				my_pixel_put(rt, x, y, 0xff0000);
			else
				my_pixel_put(rt, x, y, 0x000000);
			y++;
		}
		x++;
	}
}
