/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:13:29 by kpedro            #+#    #+#             */
/*   Updated: 2024/12/02 14:26:00 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**matrix_copy(char **matrix, int size)
{
	char	**new_mat;
	int		i;

	i = 0;
	new_mat = malloc(sizeof(char *) * (size + 1));
	if (!new_mat)
		return (NULL);
	while (i < size)
	{
		new_mat[i] = ft_strdup(matrix[i]);
		if (!new_mat[i])
		{
			free_matrix((void **)new_mat);
			return (NULL);
		}
		i++;
	}
	new_mat[size] = NULL;
	return (new_mat);
}
