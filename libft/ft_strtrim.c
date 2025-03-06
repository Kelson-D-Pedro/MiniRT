/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:10:27 by kpedro            #+#    #+#             */
/*   Updated: 2024/05/17 07:06:58 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	length;

	length = 0;
	while ((src[length] != '\0') && (length < n))
	{
		dest[length] = src[length];
		length++;
	}
	while (length < n)
	{
		dest[length] = '\0';
		length++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	beginning;
	size_t	end;
	size_t	trimmed_len;
	char	*trimmed_str;

	beginning = 0;
	length = ft_strlen(s1);
	end = length - 1;
	while (s1[beginning] && ft_strchr(set, s1[beginning]))
		beginning++;
	while (end > beginning && ft_strchr(set, s1[end]))
		end--;
	trimmed_len = end - beginning + 1;
	trimmed_str = (char *)malloc(sizeof(char) * (trimmed_len + 1));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strncpy(trimmed_str, s1 + beginning, trimmed_len);
	trimmed_str[trimmed_len] = '\0';
	return (trimmed_str);
}
