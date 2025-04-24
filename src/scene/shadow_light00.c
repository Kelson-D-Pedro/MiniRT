/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_light00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:35:34 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 16:49:37 by kpedro           ###   ########.fr       */
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

t_rgb_color	force(t_scene *rt, t_ray *ray, t_pair *obj)
{
	t_rgb_color	color;
	t_vector	light_dir;
	t_vector	point;
	double		angle;

	color.red = rt->ambiente_light.intensity * (obj->color.red
			* rt->ambiente_light.color.red / 255.0);
	color.green = rt->ambiente_light.intensity * (obj->color.green
			* rt->ambiente_light.color.green / 255.0);
	color.blue = rt->ambiente_light.intensity * (obj->color.blue
			* rt->ambiente_light.color.blue / 255.0);
	point = gen_point(obj->t, ray);
	if (is_on_dark_side(rt, point, obj->normal))
		return (color);
	light_dir = sub_vec(rt->light.pos, point);
	vector_normalize(&light_dir);
	angle = vector_dot(obj->normal, light_dir);
	if (angle > 0)
	{
		color.red += ((rt->light.color.red / 255.0) * obj->color.red)
			* rt->light.brightness * angle;
		color.green += ((rt->light.color.green / 255.0) * obj->color.green)
			* rt->light.brightness * angle;
		color.blue += ((rt->light.color.blue / 255.0) * obj->color.blue)
			* rt->light.brightness * angle;
	}
	color.red = fmin(255, color.red);
	color.green = fmin(255, color.green);
	color.blue = fmin(255, color.blue);
	return (color);
}
