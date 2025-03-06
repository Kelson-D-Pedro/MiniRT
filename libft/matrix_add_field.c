/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:32:01 by kpedro            #+#    #+#             */
/*   Updated: 2024/12/09 18:09:35 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mat_add_field(char **matrix, char *str)
{
	char	**mat;
	int		i;

	mat = malloc(sizeof(char *) * (matrix_size((void **)matrix) + 2));
	i = 0;
	while (i < matrix_size((void **)matrix))
	{
		mat[i] = ft_strdup(matrix[i]);
		if (!mat[i])
		{
			free_matrix((void **)mat);
			return (matrix);
		}
		i++;
	}
	mat[i] = ft_strdup(str);
	if (!mat[i])
	{
		printf("Error was not possible include the string\n");
		free_matrix((void **)mat);
		return (matrix);
	}
	mat[i + 1] = NULL;
	free_matrix((void **)matrix);
	return (mat);
}
