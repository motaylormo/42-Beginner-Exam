/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:56:21 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 10:36:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>//for atoi
#include <stdio.h>//for printf

int		is_prime(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return (0);
	}
	return (1);
}

int		greatest_prime_factor(int num)
{
	int factor = 2;
	int	gpf = 0;
	while (factor < num)
	{
		if (num % factor == 0 && is_prime(factor))
			gpf = factor;
		factor++;
	}
	return (gpf);
}

void	print_array(int factors[1000], int i)
{
	while (i > 0)
	{
		printf("%d*", factors[i]);
		i--;
	}
	printf("%d\n", factors[0]);
}

void	fprime(int num)
{
	int factor;
	int	factor_array[1000];
	int	i = 0;

	if (is_prime(num))
	{
		printf("%d\n", num);
		return ;
	}
	while (!is_prime(num))
	{
		factor = greatest_prime_factor(num);
		factor_array[i++] = factor;
		num /= factor;
	}
	factor_array[i] = num;
	print_array(factor_array, i);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	else
		printf("\n");
	return (0);
}
