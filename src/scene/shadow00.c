/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:35:34 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/17 14:14:57 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

int	dark_side(t_elements *rt, t_vector intersection, t_vector obj_normal)
{
	t_ray		darksaber;
	t_vector	light_dir;
	double		light_distance;

	darksaber.origin = add_vec(intersection, scalar_mult(obj_normal, EPSILON));
	light_dir = sub_vec(rt->light.pos, intersection);
	light_distance = vector_magnitude(light_dir);
	vector_normalize(&light_dir);
	darksaber.dir = light_dir;
	return (sphere_intersection(rt->sphere, &darksaber)
		|| plane_intersection(rt->plane, &darksaber)
		|| cylinder_intersection(rt->cylinder, &darksaber));
}
