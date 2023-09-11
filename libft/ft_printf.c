/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:14:42 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/01/16 16:27:16 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	find_format(va_list ptr, char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len = ft_print_char('%');
	else if (format == 'c')
		len = ft_print_char(va_arg(ptr, int));
	else if (format == 's')
		len = ft_print_str(va_arg(ptr, char *));
	else if (format == 'p')
		len = ft_print_ptr(va_arg(ptr, unsigned long int));
	else if (format == 'u')
		len = ft_print_unsigned(va_arg(ptr, unsigned int));
	else if (format == 'd' || format == 'i')
		len = ft_print_nbr(va_arg(ptr, int));
	else if (format == 'x' || format == 'X')
		len = ft_print_hexadecimal(va_arg(ptr, unsigned int), format);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		index;
	int		count;

	va_start(ptr, str);
	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			count += find_format(ptr, str[index + 1]);
			index++;
		}
		else
		{
			count += ft_print_char(str[index]);
		}
		index++;
	}
	va_end(ptr);
	return (count);
}
