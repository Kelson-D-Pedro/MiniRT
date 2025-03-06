/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:35:56 by kpedro            #+#    #+#             */
/*   Updated: 2024/12/10 15:00:20 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_cmd_path(char *cmd)
{
	int		i;
	char	*aux;
	char	*full_path;
	char	**paths;

	paths = ft_split(getenv("PATH"), ':');
	i = 0;
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_matrix((void **)paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_matrix((void **)paths);
	return (NULL);
}
