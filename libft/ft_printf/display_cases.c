/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:53:38 by kpedro            #+#    #+#             */
/*   Updated: 2024/07/13 12:19:04 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_char(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	print_str(char *s, int *counter)
{
	if (s == NULL)
		print_str("(null)", counter);
	else
	{
		while (*s)
		{
			write(1, s++, 1);
			(*counter)++;
		}
	}
}

void	print_nbr(int n, int *counter)
{
	if (n == -2147483648)
		print_str("-2147483648", counter);
	else
	{
		if (n < 0)
		{
			print_char('-', counter);
			n *= -1;
		}
		if (n > 9)
		{
			print_nbr(n / 10, counter);
			print_nbr(n % 10, counter);
		}
		else
		{
			print_char(n + '0', counter);
		}
	}
}

void	print_unsignednb(unsigned int nb, int *counter)
{
	if (nb > 9)
		print_nbr(nb / 10, counter);
	print_char((nb % 10) + 48, counter);
}
