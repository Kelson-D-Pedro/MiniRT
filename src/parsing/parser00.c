/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:49:21 by kpedro            #+#    #+#             */
/*   Updated: 2025/04/30 13:50:29 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	get_elements_quantity(t_num_of_elements *element, char *str)
{
	if (ft_strncmp(str, "A", 1) == 0)
		element->ambient_light++;
	else if (ft_strncmp(str, "C", 1) == 0)
		element->camera++;
	else if (ft_strncmp(str, "L", 1) == 0)
		element->light++;
	else if (ft_strncmp(str, "sp", 2) == 0)
		element->sphere++;
	else if (ft_strncmp(str, "pl", 2) == 0)
		element->plane++;
	else if (ft_strncmp(str, "cy", 2) == 0)
		element->cylinder++;
}

static int	verify_cap_elements01(t_num_of_elements *elements)
{
	if (elements->ambient_light <= 0 || elements->ambient_light > 1)
		return (1);
	else if (elements->camera <= 0 || elements->camera > 1)
		return (1);
	else if (elements->light <= 0 || elements->light > 1)
		return (1);
	return (0);
}

int	verify_cap_elements(t_scene *rt)
{
	int		i;
	char	**mat;

	ft_bzero(&rt->nb, sizeof(t_num_of_elements));
	i = 0;
	while (rt->map[i])
	{
		mat = ft_split_exp(rt->map[i++], ' ');
		if (!mat)
			return (1);
		get_elements_quantity(&rt->nb, mat[0]);
		free_matrix((void **)mat);
	}
	return (verify_cap_elements01(&rt->nb));
}

static int	map_lines(char *file)
{
	char	*str;
	int		counter;
	int		fd;

	counter = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		counter++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

char	**get_map(char *file_name, int i, int fd)
{
	char	**map;
	char	*line;

	i = map_lines(file_name);
	map = malloc(sizeof(char *) * (i + 1));
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (!str_isspace(line))
			map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	i = 0;
	while (i < matrix_size((void **)map))
	{
		if (ft_strcmp(map[matrix_size((void **)map) - 1], "\n") == 0)
			map[matrix_size((void **)map) - 1] = '\0';
		i++;
	}
	close(fd);
	return (map);
}
