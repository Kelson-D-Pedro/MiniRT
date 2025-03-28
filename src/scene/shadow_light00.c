/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_light00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:35:34 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/28 17:20:10 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

int	is_on_dark_side(t_scene *rt, t_vector intersection, t_vector obj_normal)
{
	t_ray		darksaber;
	t_vector	light_dir;
	double		light_distance;
	t_pair		closest;

	darksaber.origin = add_vec(intersection, scalar_mult(obj_normal, EPSILON));
	light_dir = sub_vec(rt->light.pos, intersection);
	light_distance = vector_magnitude(light_dir);
	vector_normalize(&light_dir);
	darksaber.dir = light_dir;
	closest = intersect_objs(rt, &darksaber);
	if (closest.t < light_distance)
		return (1);
	else
		return (0);
}
