/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser06.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:13:28 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 15:27:12 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	choice_who_fill(t_scene *rt, char **mat)
{
	if (ft_strcmp(mat[0], "A") == 0)
		fill_ambient_light(rt, mat);
	else if (ft_strcmp(mat[0], "L") == 0)
		fill_light(rt, mat);
	else if (ft_strcmp(mat[0], "C") == 0)
		fill_camera(rt, mat);
	else if (ft_strcmp(mat[0], "sp") == 0)
		fill_sphere(rt, mat);
	else if (ft_strcmp(mat[0], "pl") == 0)
		fill_plane(rt, mat);
	else if (ft_strcmp(mat[0], "cy") == 0)
		fill_cylinder(rt, mat);
}

void	init_3d_camera(t_scene *rt)
{
	t_vector	world_up;
	double		aspect_ratio;

	world_up.x = 0;
	world_up.y = 1;
	world_up.z = 0;
	rt->right_3d = vector_product(world_up, rt->camera.dir);
	vector_normalize(&rt->right_3d);
	rt->up_3d = vector_product(rt->camera.dir, rt->right_3d);
	vector_normalize(&rt->up_3d);
	aspect_ratio = (double)WIDTH / HEIGHT;
	rt->viewport_height = 2 * tan((rt->camera.fov * M_PI / 180.0) / 2);
	rt->viewport_width = aspect_ratio * rt->viewport_height;
}
