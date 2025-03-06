/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:25:49 by kpedro            #+#    #+#             */
/*   Updated: 2024/07/13 12:19:29 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	type_handler(char s, va_list *args, int *counter)
{
	if (s == 'c')
		print_char(va_arg(*args, int), counter);
	else if (s == 's')
		print_str(va_arg(*args, char *), counter);
	else if (s == 'd' || s == 'i')
		print_nbr(va_arg(*args, int), counter);
	else if (s == 'u')
		print_unsignednb(va_arg(*args, unsigned int), counter);
	else if (s == 'p')
		print_pointer(va_arg(*args, void *), counter);
	else if (s == 'x' || s == 'X')
		print_hex(va_arg(*args, unsigned int), s, counter);
	else if (s == '%')
		print_char('%', counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			type_handler(str[i], &args, &counter);
		}
		else
			print_char(str[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
