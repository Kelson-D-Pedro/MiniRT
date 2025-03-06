/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser06.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:13:28 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/03 17:31:07 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	choice_who_fill(t_elements *rt, char **mat)
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

void	normalize(t_elements *rt)
{
	if (!is_normalized(rt->camera.orientation))
		vector_normalize(&rt->camera.orientation);
	if (rt->nb.cylinder)
		if (!is_normalized(rt->cylinder->normal_vector))
			vector_normalize(&rt->cylinder->normal_vector);
	if (rt->nb.plane)
		if (!is_normalized(rt->plane->normal_vector))
			vector_normalize(&rt->plane->normal_vector);
}
