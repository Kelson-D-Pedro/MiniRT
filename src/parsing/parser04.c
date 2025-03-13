/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:01:29 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/13 11:49:55 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

int	verify_plane(char **mat)
{
	int	i;

	if (matrix_size((void **)mat) != 4)
	{
		ft_putstr_fd("Error\nmissing values in Plane\n", 2);
		return (1);
	}
	i = verify_vector_values(mat[1]);
	i = verify_color(mat[3], 0);
	i = verify_normalized_vector(mat[2]);
	return (i);
}

int	verify_cylinder(char **mat)
{
	int	i;

	if (matrix_size((void **)mat) != 6)
	{
		ft_putstr_fd("Error\nmissing values in Cylinder\n", 2);
		return (1);
	}
	i = verify_vector_values(mat[1]);
	i = verify_color(mat[5], 0);
	i = verify_normalized_vector(mat[2]);
	if (!str_is_digit(mat[3]))
	{
		ft_putstr_fd("Error\nnon-numeric in Cylinder diameter\n", 2);
		return (1);
	}
	if (!str_is_digit(mat[4]))
	{
		ft_putstr_fd("Error\nnon-numeric in Cylinder height\n", 2);
		return (1);
	}
	return (i);
}

int	its_alright_to_start(t_elements *rt, char **argv, int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("ERROR:\nHow to use:\n.\\miniRT filename", 2);
		return (1);
	}
	rt->map = get_map(argv[1]);
	if (!rt->map)
	{
		ft_putstr_fd("ERROR: Mapa Invalido\n", 2);
		return (1);
	}
	if (verify_file_stuffs(argv[1], rt))
		return (1);
	if (verify_rt_file(rt))
		return (1);
	return (0);
}

void	fill_ambient_light(t_elements *rt, char **mat)
{
	char	**colors;

	rt->ambiente_light.intensity = ft_atod(mat[1], 1, 0, 0);
	colors = ft_split(mat[2], ',');
	rt->ambiente_light.color.red = ft_atoi(colors[0]);
	rt->ambiente_light.color.green = ft_atoi(colors[1]);
	rt->ambiente_light.color.blue = ft_atoi(colors[2]);
	free_matrix((void **)colors);
	return ;
}

void	fill_camera(t_elements *rt, char **mat)
{
	char	**vector;

	vector = ft_split(mat[1], ',');
	rt->camera.pos.x = ft_atod(vector[0], 1, 0, 0);
	rt->camera.pos.y = ft_atod(vector[1], 1, 0, 0);
	rt->camera.pos.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	vector = ft_split(mat[2], ',');
	rt->camera.dir.x = ft_atod(vector[0], 1, 0, 0);
	rt->camera.dir.y = ft_atod(vector[1], 1, 0, 0);
	rt->camera.dir.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	rt->camera.fov = ft_atod(mat[3], 1, 0, 0);
	return ;
}
