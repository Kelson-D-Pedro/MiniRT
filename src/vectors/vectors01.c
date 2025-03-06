/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:10:20 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/03 16:28:10 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	vector_normalize(t_vector *vec)
{
	double	magnitude;

	magnitude = vector_magnitude(*vec);
	if (magnitude == 0)
		return ;
	vec->x /= magnitude;
	vec->y /= magnitude;
	vec->z /= magnitude;
}
double	vector_magnitude(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

double	vector_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

int	is_null(t_vector vec)
{
	return (vec.x == 0 && vec.y == 0 && vec.z == 0);
}

int	is_normalized(t_vector vec)
{
	double	magnitude;

	magnitude = vector_magnitude(vec);
	return (fabs(magnitude - 1.0) < EPSILON);
}
