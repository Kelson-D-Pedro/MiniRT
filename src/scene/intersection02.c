/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darwin <darwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:54:47 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/30 20:44:12 by darwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_pair	intersect_objs(t_scene *rt, t_ray *ray)
{
	t_pair	closest;
	t_pair	sp;
	t_pair	cy;
	t_pair	pl;

	closest.t = -1;
	sp = which_sphere(rt, ray);
	cy = which_cylinder(rt, ray);
	pl = which_plane(rt, ray);
	if (sp.t > 0 && (closest.t == -1 || sp.t < closest.t))
		closest = sp;
	if (pl.t > 0 && (closest.t == -1 || pl.t < closest.t))
	{
		closest = pl;
		closest.type = 2;

	}
	if (cy.t > 0 && (closest.t == -1 || cy.t < closest.t))
		closest = cy;
	return (closest);
}
