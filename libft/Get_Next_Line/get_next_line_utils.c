/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:06:45 by kpedro            #+#    #+#             */
/*   Updated: 2024/07/13 12:04:58 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined_str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2))
				+ 1));
	if (joined_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			joined_str[i] = s1[i];
	while (s2[j] != '\0')
		joined_str[i++] = s2[j++];
	joined_str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (joined_str);
}
