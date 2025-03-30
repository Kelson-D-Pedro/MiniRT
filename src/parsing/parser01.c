/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:41:49 by kpedro            #+#    #+#             */
/*   Updated: 2025/03/18 11:41:17 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static int	verify_others(char *str)
{
	if (ft_strncmp(str, "A", 1))
		return (1);
	else if (ft_strncmp(str, "C", 1))
		return (1);
	else if (ft_strncmp(str, "L", 1))
		return (1);
	else if (ft_strncmp(str, "sp", 1))
		return (1);
	else if (ft_strncmp(str, "pl", 1))
		return (1);
	else if (ft_strncmp(str, "cy", 1))
		return (1);
	return (0);
}

int	verify_others_elements(char *file_name)
{
	char	**mat;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		mat = ft_split_exp(line, ' ');
		if (!mat[0])
		{
			if (verify_others(mat[0]))
			{
				free_matrix((void **)mat);
				free(line);
				close(fd);
				return (1);
			}
		}
		free_matrix((void **)mat);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	verify_file_stuffs(char *file_name, t_scene *rt)
{
	if (verify_cap_elements(rt) || verify_others_elements(file_name))
	{
		ft_putstr_fd("ERROR: Missing/Too Much Elements\n", 2);
		return (1);
	}
	if (verify_file_extension(file_name))
	{
		ft_putstr_fd("ERROR: Wrong File Extension\n", 2);
		return (1);
	}
	return (0);
}

int	verify_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if ((ft_strcmp(&file[len - 3], ".rt") == 0) || (ft_strcmp(file,
				".rt") == 0))
		return (0);
	return (1);
}
