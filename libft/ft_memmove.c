/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:00:02 by kpedro            #+#    #+#             */
/*   Updated: 2024/05/17 07:05:23 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*aux_dest;
	const char	*aux_src;
	size_t		i;

	aux_dest = (char *)dest;
	aux_src = (const char *)src;
	i = 0;
	if (aux_dest < aux_src)
	{
		while (i < n)
		{
			aux_dest[i] = aux_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			aux_dest[i] = aux_src[i];
		}
	}
	return (dest);
}
