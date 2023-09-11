/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:55:04 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/01/02 12:19:17 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unsigned_size(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*result;
	int		len;
	int		index;

	index = 1;
	len = ft_unsigned_size(n);
	result = (char *)malloc(len + 1);
	if (NULL == result)
	{
		return (0);
	}
	result[len] = '\0';
	while (n != 0)
	{
		result[len - index] = '0' + (n % 10);
		n /= 10;
		index++;
	}
	return (result);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
	{
		len += write(1, "0", 1);
	}
	else
	{
		num = ft_uitoa(n);
		len = ft_print_str(num);
		free(num);
	}
	return (len);
}
