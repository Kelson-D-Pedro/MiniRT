/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:57:33 by kpedro            #+#    #+#             */
/*   Updated: 2024/12/10 14:57:55 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv_value(char **mat, char *var_name)
{
	int	i;
	int	size;

	if (!mat || !var_name)
		return (NULL);
	size = ft_strlen(var_name);
	i = 0;
	while (mat[i])
	{
		if (ft_strncmp(mat[i], var_name, size) == 0 && mat[i][size] == '=')
			return (mat[i] + size + 1);
		i++;
	}
	return (NULL);
}
