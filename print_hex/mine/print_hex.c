/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:19:47 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 09:40:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int sign = 1;
	int num = 0;
	while (*str && (*str < 33 || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

void	print_hex(unsigned int num)
{
	unsigned int	digit;
	unsigned int	div = 1;
	unsigned int	copy = num;

	while ((copy = copy / 16))
		div *= 16;
	while (div >= 1)
	{
		digit = num / div;
		num %= div;
		div /= 16;
		digit = (digit < 10) ? digit + '0' : digit - 10 + 'a';
		ft_putchar(digit);
	}
}

int		main(int ac, char **av)
{
	int	num;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		if (num >= 0)
			print_hex(num);
	}
	ft_putchar('\n');
	return (0);
}
