/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darwin <darwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:48:42 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/30 20:33:18 by darwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

/*t_ray	send_rays(t_scene *rt, int x, int y)
{
	t_ray		ray;
	double		viewport_x;
	double		viewport_y;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	left_inf_point;

	viewport_x = (double)x / (WIDTH);
	viewport_y = 1.0 - (double)y / (HEIGHT);
	horizontal = scalar_mult(rt->right_3d, rt->viewport_width);
	vertical = scalar_mult(rt->up_3d, rt->viewport_height);
	left_inf_point = sub_vec(rt->camera.pos, add_vec(scalar_mult(horizontal,
					0.5), add_vec(scalar_mult(vertical, 0.5), rt->camera.dir)));
	ray.origin = rt->camera.pos;
	ray.dir = sub_vec(add_vec(left_inf_point, add_vec(scalar_mult(horizontal,
						viewport_x), scalar_mult(vertical, viewport_y))),
			rt->camera.pos);
	vector_normalize(&ray.dir);
	ray.dir.z *= -0.5;
	return (ray);
}*/

t_ray	send_rays(t_scene *rt, int x, int y)
{
	t_ray		ray;
	double		viewport_x;
	double		viewport_y;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	left_inf_point;

	viewport_x = (double)x / (WIDTH - 1);
	viewport_y = (double)y / (HEIGHT - 1);
	horizontal = scalar_mult(rt->right_3d, rt->viewport_width);
	vertical = scalar_mult(rt->up_3d, -rt->viewport_height);
	left_inf_point = sub_vec(
		add_vec(rt->camera.pos, rt->camera.dir),
		add_vec(scalar_mult(horizontal, 0.5), scalar_mult(vertical, 0.5))
	);
	ray.origin = rt->camera.pos;
	ray.dir = sub_vec(
		add_vec(left_inf_point,
			add_vec(scalar_mult(horizontal, viewport_x),
					scalar_mult(vertical, viewport_y))),
		rt->camera.pos
	);
	vector_normalize(&ray.dir);
	return (ray);
}

