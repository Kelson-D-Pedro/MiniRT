/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:34:43 by kpedro            #+#    #+#             */
/*   Updated: 2024/05/17 07:01:55 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*auxiliar;

	auxiliar = (unsigned char *) s;
	while (n > 0)
	{
		*auxiliar = '\0';
		auxiliar++;
		n--;
	}
}
