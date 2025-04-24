/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:33:12 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/24 14:23:47 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void    x_axis_translate(t_vector *pos, double delta, char op, int *ctrl)
{
    if (op == '+')
        pos->x += delta;
    else if (op == '-')
        pos->x -= delta;
    *ctrl = 1;
}

void    y_axis_translate(t_vector *pos, double delta, char op, int *ctrl)
{
    if (op == '+')
        pos->y += delta;
    else if (op == '-')
        pos->y -= delta;
    *ctrl = 1;
}

void    z_axis_translate(t_vector *pos, double delta, char op, int *ctrl)
{
    if (op == '+')
        pos->z += delta;
    else if (op == '-')
        pos->z -= delta;
    *ctrl = 1;
}