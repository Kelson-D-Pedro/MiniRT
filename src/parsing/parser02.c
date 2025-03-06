/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:26:37 by kpedro            #+#    #+#             */
/*   Updated: 2025/02/19 15:07:06 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

int	verify_color(char *str1, int i)
{
	int		value;
	char	**str;

	str = ft_split(str1, ',');
	if (matrix_size((void **)str) != 3)
	{
		ft_putstr_fd("Error\nMissing/Too Much Values in Colors\n", 2);
		free_matrix((void **)str);
		return (1);
	}
	while (str[i])
	{
		value = ft_atoi(str[i++]);
		if (value < 0 || value > 255)
		{
			ft_putstr_fd("Error\nvalue out of range in colors\n", 2);
			return (1);
		}
	}
	free_matrix((void **)str);
	return (0);
}

int	verify_vector_values(char *str)
{
	char	**mat;
	int		i;

	mat = ft_split(str, ',');
	i = 0;
	if (matrix_size((void **)mat) != 3)
	{
		ft_putstr_fd("Error\nMissing/Too Much Values in Vector\n", 2);
		free_matrix((void **)mat);
		return (1);
	}
	while (mat[i])
	{
		if (!str_is_digit(mat[i]))
		{
			ft_putstr_fd("Error\nnon-numeric in vector\n", 2);
			free_matrix((void **)mat);
			return (1);
		}
		i++;
	}
	free_matrix((void **)mat);
	return (0);
}

static int	normalized_vect_range(double x, double y, double z)
{
	if (x < -1 || x > 1 || y < -1 || y > 1 || z < -1 || z > 1)
	{
		ft_putstr_fd("Error\nnormalize vector has values out of range\n", 2);
		return (1);
	}
	return (0);
}

int	verify_normalized_vector(char *str)
{
	char	**mat;
	double	x;
	double	y;
	double	z;

	mat = ft_split(str, ',');
	if (matrix_size((void **)mat) != 3)
	{
		ft_putstr_fd("Error\nMissing/Too Much Values in Normal Vector\n", 2);
		free_matrix((void **)mat);
		return (1);
	}
	x = ft_atod(mat[0], 1, 0, 0);
	y = ft_atod(mat[1], 1, 0, 0);
	z = ft_atod(mat[2], 1, 0, 0);
	free_matrix((void **)mat);
	if (is_null(vector_new(x, y, z)))
	{
		ft_putstr_fd("Error\nnormalize vector is NULL\n", 2);
		return (1);
	}
	if (normalized_vect_range(x, y, z))
		return (1);
	return (0);
}

int	verify_rt_file(t_elements *rt)
{
	char	**mat;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (rt->map[i])
	{
		mat = ft_split_exp(rt->map[i], ' ');
		if (!mat)
			return (1);
		j = verify_elements(mat);
		free_matrix((void **)mat);
		if (j)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
