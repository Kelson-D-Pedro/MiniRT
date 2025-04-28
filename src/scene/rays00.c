/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:48:42 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 10:27:43 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_ray	send_rays(t_scene *rt, int x, int y)
{
	t_ray		ray;
	double		viewport_x;
	double		viewport_y;
	t_vector	horizontal;
	t_vector	vertical;

	viewport_x = (double)x / (WIDTH - 1);
	viewport_y = (double)y / (HEIGHT - 1);
	horizontal = scalar_mult(rt->right_3d, rt->viewport_width);
	vertical = scalar_mult(rt->up_3d, -rt->viewport_height);
	rt->left_inf_point = sub_vec(add_vec(rt->camera.pos, rt->camera.dir),
			add_vec(scalar_mult(horizontal, 0.5), scalar_mult(vertical, 0.5)));
	ray.origin = rt->camera.pos;
	ray.dir = sub_vec(add_vec(rt->left_inf_point,
				add_vec(scalar_mult(horizontal, viewport_x),
					scalar_mult(vertical, viewport_y))), rt->camera.pos);
	vector_normalize(&ray.dir);
	return (ray);
}
