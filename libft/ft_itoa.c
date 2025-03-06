/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:40:23 by kpedro            #+#    #+#             */
/*   Updated: 2024/05/17 10:19:57 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_number(int nb)
{
	size_t	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t			number_len;
	char			*str;
	unsigned int	num;

	number_len = digits_number(n);
	str = (char *)malloc(sizeof(char) * (number_len + 1));
	if (!str)
		return (NULL);
	str[number_len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (num)
	{
		str[--number_len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
