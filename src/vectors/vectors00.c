/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:55:21 by darwin            #+#    #+#             */
/*   Updated: 2025/04/23 16:39:08 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_vector	vector_new(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vector	sub_vec(t_vector vec_1, t_vector vec_2)
{
	t_vector	vec;

	vec.x = vec_1.x - vec_2.x;
	vec.y = vec_1.y - vec_2.y;
	vec.z = vec_1.z - vec_2.z;
	return (vec);
}

t_vector	add_vec(t_vector vec_1, t_vector vec_2)
{
	t_vector	vec;

	vec.x = vec_1.x + vec_2.x;
	vec.y = vec_1.y + vec_2.y;
	vec.z = vec_1.z + vec_2.z;
	return (vec);
}

t_vector	scalar_mult(t_vector vect, double scalar)
{
	t_vector	vec;

	vec.x = vect.x * scalar;
	vec.y = vect.y * scalar;
	vec.z = vect.z * scalar;
	return (vec);
}

t_vector	vector_product(t_vector vec_1, t_vector vec_2)
{
	t_vector	vec;

	vec.x = (vec_1.y * vec_2.z) - (vec_1.z * vec_2.y);
	vec.y = (vec_1.z * vec_2.x) - (vec_1.x * vec_2.z);
	vec.z = (vec_1.x * vec_2.y) - (vec_1.y * vec_2.x);
	return (vec);
}
