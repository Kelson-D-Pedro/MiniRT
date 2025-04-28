/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:36:09 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 10:02:28 by kpedro           ###   ########.fr       */
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
	t_vector	v;
	t_vector	proj;
	t_vector	normal;
	double		proj_len;

	v = sub_vec(point, cy->pos);
	proj_len = vector_dot(v, cy->dir);
	if (fabs(proj_len - (cy->height / 2)) < EPSILON)
		return (cy->dir);
	if (fabs(proj_len + (cy->height / 2)) < EPSILON)
		return (scalar_mult(cy->dir, -1));
	proj = scalar_mult(cy->dir, proj_len);
	normal = sub_vec(v, proj);
	vector_normalize(&normal);
	return (normal);
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
	mlx_clear_window(rt->mini_lx.mlx, rt->mini_lx.win);
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
