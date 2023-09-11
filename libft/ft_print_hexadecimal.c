/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:18:50 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/01/03 11:50:32 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexadecimal_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_puthex_fd(unsigned int n, int fd, char format)
{
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd, format);
		ft_puthex_fd(n % 16, fd, format);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar_fd(n + '0', fd);
		}
		else
		{
			if (format == 'X')
			{
				ft_putchar_fd((n - 10 + 'A'), fd);
			}
			else if (format == 'x')
			{
				ft_putchar_fd((n - 10 + 'a'), fd);
			}
		}
	}
}

int	ft_print_hexadecimal(unsigned int n, char format)
{
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	else
		ft_puthex_fd(n, 1, format);
	return (ft_hexadecimal_len(n));
}
