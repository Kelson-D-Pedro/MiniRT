/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:48:42 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/24 12:54:16 by kpedro           ###   ########.fr       */
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
}

/* t_ray send_rays(t_scene *rt, int x, int y)
{
	t_ray		ray;
	double		viewport_x;
	double		viewport_y;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	viewport_center;
	t_vector	viewport_upper_left;
	t_vector	point_on_viewport;

	// Converter coordenadas de pixel para coordenadas do viewport (0.0 a 1.0)
	viewport_x = (double)x / (WIDTH);
	viewport_y = 1.0 - (double)y / (HEIGHT);
	// Calcular vetores horizontal e vertical do viewport
	horizontal = scalar_mult(rt->right_3d, rt->viewport_width);
	vertical = scalar_mult(rt->up_3d, rt->viewport_height);
	// Calcular o centro do viewport - a posição para onde a câmera aponta
	viewport_center = add_vec(rt->camera.pos, rt->camera.dir);
	// Calcular o ponto superior esquerdo do viewport
	viewport_upper_left = sub_vec(viewport_center,
							add_vec(scalar_mult(horizontal, 0.5),
									scalar_mult(vertical, 0.5)));
	// Calcular o ponto específico no viewport para este pixel
	point_on_viewport = add_vec(viewport_upper_left,
							add_vec(scalar_mult(horizontal, viewport_x),
								scalar_mult(vertical, viewport_y)));
	// Definir origem do raio como posição da câmera
	ray.origin = rt->camera.pos;
	// Calcular direção do raio e normalizar
	ray.dir = sub_vec(point_on_viewport, ray.origin);
	vector_normalize(&ray.dir);
	return (ray);
}
 */