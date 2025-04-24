/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:54:47 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 16:48:56 by kpedro           ###   ########.fr       */
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
		closest = pl;
	if (cy.t > 0 && (closest.t == -1 || cy.t < closest.t))
		closest = cy;
	return (closest);
}
