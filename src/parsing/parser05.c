/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:48:59 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/07 11:44:54 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	fill_light(t_elements *rt, char **mat)
{
	char	**vector;

	vector = ft_split(mat[1], ',');
	rt->light.position.x = ft_atod(vector[0], 1, 0, 0);
	rt->light.position.y = ft_atod(vector[1], 1, 0, 0);
	rt->light.position.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	vector = ft_split(mat[3], ',');
	rt->light.color.red = ft_atoi(vector[0]);
	rt->light.color.green = ft_atoi(vector[1]);
	rt->light.color.blue = ft_atoi(vector[2]);
	free_matrix((void **)vector);
	rt->light.brightness = ft_atod(mat[2], 1, 0, 0);
}

void	fill_sphere(t_elements *rt, char **mat)
{
	static int	i;
	char		**vector;

	vector = ft_split(mat[1], ',');
	rt->sphere[i].position.x = ft_atod(vector[0], 1, 0, 0);
	rt->sphere[i].position.y = ft_atod(vector[1], 1, 0, 0);
	rt->sphere[i].position.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	vector = ft_split(mat[3], ',');
	rt->sphere[i].color.red = ft_atoi(vector[0]);
	rt->sphere[i].color.green = ft_atoi(vector[1]);
	rt->sphere[i].color.blue = ft_atoi(vector[2]);
	free_matrix((void **)vector);
	rt->sphere[i].diameter = ft_atod(mat[2], 1, 0, 0);
	rt->sphere[i].radius = rt->sphere[i].diameter / 2;
	i++;
	return ;
}

void	fill_plane(t_elements *rt, char **mat)
{
	char		**vector;
	static int	i;

	vector = ft_split(mat[1], ',');
	rt->plane[i].position.x = ft_atod(vector[0], 1, 0, 0);
	rt->plane[i].position.y = ft_atod(vector[1], 1, 0, 0);
	rt->plane[i].position.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	vector = ft_split(mat[2], ',');
	rt->plane[i].normal_vector.x = ft_atod(vector[0], 1, 0, 0);
	rt->plane[i].normal_vector.y = ft_atod(vector[1], 1, 0, 0);
	rt->plane[i].normal_vector.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	vector = ft_split(mat[3], ',');
	rt->plane[i].color.red = ft_atoi(vector[0]);
	rt->plane[i].color.green = ft_atoi(vector[1]);
	rt->plane[i].color.blue = ft_atoi(vector[2]);
	free_matrix((void **)vector);
	i++;
	return ;
}

void	fill_cylinder(t_elements *rt, char **mat)
{
	char		**vector;
	static int	i;

	vector = ft_split(mat[1], ',');
	rt->cylinder[i].position.x = ft_atod(vector[0], 1, 0, 0);
	rt->cylinder[i].position.y = ft_atod(vector[1], 1, 0, 0);
	rt->cylinder[i].position.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	vector = ft_split(mat[2], ',');
	rt->cylinder[i].normal_vector.x = ft_atod(vector[0], 1, 0, 0);
	rt->cylinder[i].normal_vector.y = ft_atod(vector[1], 1, 0, 0);
	rt->cylinder[i].normal_vector.z = ft_atod(vector[2], 1, 0, 0);
	free_matrix((void **)vector);
	vector = ft_split(mat[5], ',');
	rt->cylinder[i].color.red = ft_atoi(vector[0]);
	rt->cylinder[i].color.green = ft_atoi(vector[1]);
	rt->cylinder[i].color.blue = ft_atoi(vector[2]);
	free_matrix((void **)vector);
	rt->cylinder[i].diameter = ft_atod(mat[3], 1, 0, 0);
	rt->cylinder[i].height = ft_atod(mat[4], 1, 0, 0);
	rt->cylinder[i].radius = rt->cylinder[i].diameter / 2;
	i++;
	return ;
}

void	fill_elements(t_elements *rt)
{
	char	**mat;
	int		i;

	i = 0;
	rt->sphere = malloc(sizeof(t_sphere) * rt->nb.sphere);
	rt->plane = malloc(sizeof(t_plane) * rt->nb.plane);
	rt->cylinder = malloc(sizeof(t_cylinder) * rt->nb.cylinder);
	while (rt->map[i])
	{
		mat = ft_split(rt->map[i], ' ');
		choice_who_fill(rt, mat);
		free_matrix((void **)mat);
		i++;
	}
	normalize(rt);
}
