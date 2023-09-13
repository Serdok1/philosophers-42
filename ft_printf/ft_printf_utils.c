/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:40:35 by sozbayra          #+#    #+#             */
/*   Updated: 2023/03/29 11:28:59 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	return (i);
}

int	ft_ptr_len(int decimal)
{
	int	i;

	i = 0;
	while (decimal != 0)
	{
		decimal /= 16;
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long decimal)
{
	int	i;

	if (!decimal)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	i = ft_hex_convert_lower(decimal);
	i += 2;
	return (i);
}

int	ft_print_hex(unsigned int decimal, int key)
{
	int	length;

	length = ft_ptr_len(decimal);
	if (key == 1)
		return (ft_hex_convert_upper(decimal));
	else
		return (ft_hex_convert_lower(decimal));
}

int	ft_hex_convert_upper(unsigned long decimal)
{
	int					i;
	int					remainder;
	unsigned long long	quotient;
	char				write_char[100];

	quotient = decimal;
	i = 0;
	remainder = 0;
	if (quotient == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			write_char[i++] = '0' + remainder;
		else
			write_char[i++] = remainder - 10 + 'A';
		quotient = quotient / 16;
	}
	return (ft_hex_write(write_char, i));
}
