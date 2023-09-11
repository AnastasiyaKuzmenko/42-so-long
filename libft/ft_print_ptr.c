/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:41:59 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/01/16 10:45:29 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(unsigned long int n)
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

static void	ft_putptr_fd(unsigned long int n, int fd)
{
	if (n >= 16)
	{
		ft_putptr_fd(n / 16, fd);
		ft_putptr_fd(n % 16, fd);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar_fd(n + '0', fd);
		}
		else
		{
			ft_putchar_fd((n - 10 + 'a'), fd);
		}
	}
}

int	ft_print_ptr(unsigned long int n)
{
	int	len;

	len = write(1, "0x", 2);
	if (n == 0)
	{
		len += write(1, "0", 1);
	}
	else
	{
		ft_putptr_fd(n, 1);
		len += ft_ptr_len(n);
	}
	return (len);
}
