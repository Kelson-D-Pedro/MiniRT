/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:52:03 by kpedro            #+#    #+#             */
/*   Updated: 2024/07/13 12:18:47 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_hex(unsigned int nb, char c, int *counter)
{
	if (nb > 15)
		print_hex(nb / 16, c, counter);
	if (c == 'x')
		print_char("0123456789abcdef"[nb % 16], counter);
	else
		print_char("0123456789ABCDEF"[nb % 16], counter);
}

static void	print_pointer_aux(unsigned long long nb, int *counter)
{
	if (nb > 15)
		print_pointer_aux(nb / 16, counter);
	print_char("0123456789abcdef"[nb % 16], counter);
}

void	print_pointer(void *ptr, int *counter)
{
	if (ptr == NULL || ptr == 0)
	{
		print_str("(nil)", counter);
		return ;
	}
	write(1, "0x", 2);
	(*counter) += 2;
	print_pointer_aux((unsigned long long)ptr, counter);
}
