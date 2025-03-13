/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:36:09 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/13 14:38:43 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_vector	gen_point(double t, t_ray *ray)
{
	t_vector	point;

	point.x = ray->origin.x + t * ray->dir.x;
	point.y = ray->origin.y + t * ray->dir.y;
	point.z = ray->origin.z + t * ray->dir.z;
	return (point);
}
