/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:27:59 by darwin            #+#    #+#             */
/*   Updated: 2024/10/28 12:19:54 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mat_to_str(char **matrix)
{
	char	*str;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	while (matrix[i])
		total_len += ft_strlen(matrix[i++]);
	str = malloc(sizeof(char *) * total_len + 1);
	str[0] = '\0';
	i = 0;
	while (matrix[i])
	{
		ft_strcat(str, matrix[i]);
		if (matrix[i + 1])
			ft_strcat(str, " ");
		i++;
	}
	return (str);
}
