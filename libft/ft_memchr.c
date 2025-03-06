/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:51:34 by kpedro            #+#    #+#             */
/*   Updated: 2024/05/17 07:05:10 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t	n)
{
	unsigned char	*auxiliar;

	auxiliar = (unsigned char *)s;
	while (n--)
	{
		if (*auxiliar == (unsigned char)c)
			return (auxiliar);
		auxiliar++;
	}
	return (NULL);
}
