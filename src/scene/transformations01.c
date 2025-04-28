/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:36:45 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/28 11:18:17 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	z_axis_rotation(t_vector *pos, double angle, int *ctrl)
{
	double	x;
	double	y;

	x = pos->x;
	y = pos->y;
	pos->x = (x * cos(angle)) - (y * sin(angle));
	pos->y = (x * sin(angle)) + (y * cos(angle));
	*ctrl = 1;
}

void	cylinder_size_up_down(t_cylinder *cy, char op, double delta, int *i)
{
	if (op == '-')
		cy->height -= delta;
	else if (op == '+')
		cy->height += delta;
	*i = 1;
}

void	sphere_size_up_down(t_sphere *sp, char op, double delta, int *i)
{
	if (op == '-')
	{
		sp->diameter -= delta;
		sp->radius = sp->diameter / 2;
	}
	else if (op == '+')
	{
		sp->diameter += delta;
		sp->radius = sp->diameter / 2;
	}
	*i = 1;
}
