/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:47:10 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/14 15:45:45 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# ifndef EPSILON
#  define EPSILON 1e-6
# endif

//
//------------------------------- STRUCTURES
//

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

//
//------------------------------- T_VECTOR FUNCTIONS
//

t_vector	vector_new(double x, double y, double z);
t_vector	sub_vec(t_vector vec_1, t_vector vec_2);
t_vector	add_vec(t_vector vec_1, t_vector vec_2);
t_vector	scalar_mult(t_vector vect, double scalar);
t_vector	vector_product(t_vector vec_1, t_vector vec_2);

//
//------------------------------- DOUBLE FUNCTIONS
//

double		vector_magnitude(t_vector vec);
double		vector_dot(t_vector v1, t_vector v2);

//
//------------------------------- VOID FUNCTIONS
//

void		vector_normalize(t_vector *vec);

//
//------------------------------- INT FUNCTIONS
//

int			is_null(t_vector vec);
int			is_normalized(t_vector vec);

#endif