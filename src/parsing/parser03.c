/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:01:11 by kpedro            #+#    #+#             */
/*   Updated: 2025/02/19 12:17:16 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

int	verify_elements(char **mat)
{
	if (ft_strcmp(mat[matrix_size((void **)mat) - 1], "\n") == 0)
		mat[matrix_size((void **)mat) - 1] = '\0';
	if (ft_strcmp(mat[0], "A") == 0)
		return (verify_ambient_light(mat));
	else if (ft_strcmp(mat[0], "L") == 0)
		return (verify_light(mat));
	else if (ft_strcmp(mat[0], "C") == 0)
		return (verify_camera(mat));
	else if (ft_strcmp(mat[0], "sp") == 0)
		return (verify_sphere(mat));
	else if (ft_strcmp(mat[0], "pl") == 0)
		return (verify_plane(mat));
	else if (ft_strcmp(mat[0], "cy") == 0)
		return (verify_cylinder(mat));
	return (0);
}

int	verify_ambient_light(char **mat)
{
	int		i;
	double	lighting;

	if (matrix_size((void **)mat) != 3)
		return (1);
	i = verify_color(mat[2], 0);
	if (!str_is_digit(mat[1]))
	{
		ft_putstr_fd("Error\nnon-numeric in ambient lighting\n", 2);
		return (1);
	}
	lighting = ft_atod(mat[1], 1, 0, 0);
	if ((lighting < 0) || (lighting > 1))
	{
		ft_putstr_fd("Error\nvalue out of range in ambient lighting ratio\n",
			2);
		return (1);
	}
	return (i);
}

int	verify_camera(char **mat)
{
	int		j;
	double	fov;

	if (matrix_size((void **)mat) != 4)
	{
		ft_putstr_fd("Error\nmissing or extra values in camera\n", 2);
		return (1);
	}
	j = 0;
	j = verify_vector_values(mat[1]);
	j = verify_normalized_vector(mat[2]);
	if (!str_is_digit(mat[3]))
	{
		ft_putstr_fd("Error\nnon-numeric in FOV\n", 2);
		return (1);
	}
	fov = ft_atod(mat[2], 1, 0, 0);
	if ((fov < 0) || (fov > 180))
	{
		ft_putstr_fd("Error\nFOV out of range in Camera\n", 2);
		return (1);
	}
	return (j);
}

int	verify_light(char **mat)
{
	int		i;
	double	brightness;

	if (matrix_size((void **)mat) != 4)
	{
		ft_putstr_fd("Error\nmissing or extra values in Light\n", 2);
		return (1);
	}
	i = verify_vector_values(mat[1]);
	i = verify_color(mat[3], 0);
	if (!str_is_digit(mat[2]))
	{
		ft_putstr_fd("Error\nnon-numeric in light brightness\n", 2);
		return (1);
	}
	brightness = ft_atod(mat[2], 1, 0, 0);
	if ((brightness < 0) || (brightness > 1))
	{
		ft_putstr_fd("Error\nvalue out of range in light brightness\n", 2);
		return (1);
	}
	return (i);
}

int	verify_sphere(char **mat)
{
	int	i;

	if (matrix_size((void **)mat) != 4)
	{
		ft_putstr_fd("Error\nmissing or extra values in Sphere\n", 2);
		return (1);
	}
	i = verify_vector_values(mat[1]);
	i = verify_color(mat[3], 0);
	if (!str_is_digit(mat[2]))
	{
		ft_putstr_fd("Error\nnon-numeric in Sphere diameter's\n", 2);
		return (1);
	}
	return (i);
}
