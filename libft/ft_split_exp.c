/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:01:27 by kpedro            #+#    #+#             */
/*   Updated: 2025/02/19 12:02:24 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_word(char **new_str, const char *str, size_t word_len)
{
	*new_str = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!*new_str)
		return (0);
	ft_strlcpy(*new_str, str, word_len + 1);
	return (1);
}

static int	handle_quotes(int *in_quotes, char c)
{
	if (*in_quotes == 0 && (c == '\'' || c == '\"'))
		*in_quotes = c;
	else if (*in_quotes == c)
		*in_quotes = 0;
	return (*in_quotes);
}

static size_t	get_word_len(const char *str, char delim)
{
	int		in_quotes;
	size_t	len;

	in_quotes = 0;
	len = 0;
	while (str[len] && ((str[len] != delim && str[len] != '\t') || in_quotes))
	{
		handle_quotes(&in_quotes, str[len]);
		len++;
	}
	return (len);
}

size_t	ft_countword(char const *s, char c)
{
	size_t	count;
	int		in_quotes;

	count = 0;
	in_quotes = 0;
	while (*s)
	{
		while (*s == c && *s != '\t')
			s++;
		if (*s)
			count++;
		while (*s && ((*s != c && *s != '\t') || in_quotes))
		{
			if (*s == '\"' || *s == '\'')
			{
				if (in_quotes == 0)
					in_quotes = *s;
				else if (in_quotes == *s)
					in_quotes = 0;
			}
			s++;
		}
	}
	return (count);
}

char	**ft_split_exp(char *str, char delim)
{
	char	**result;
	size_t	word_count;
	size_t	i;
	size_t	word_len;

	word_count = ft_countword(str, delim);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str && i < word_count)
	{
		while (*str == delim)
			str++;
		word_len = get_word_len(str, delim);
		if (!alloc_word(&result[i], str, word_len))
		{
			free_matrix((void **)result);
			return (NULL);
		}
		str += word_len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
