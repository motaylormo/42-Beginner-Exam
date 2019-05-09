/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:22:46 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 09:43:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		is_opp(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

/*
**	This while structure allows for the first char being '-'
*/
int		contains_digit(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (1);
		str++;
	}
	return (0);
}

void	solve_op(int n1, char opp, int n2)
{
	if (opp == '+')
		printf("%d\n", n1 + n2);
	else if (opp == '-')
		printf("%d\n", n1 - n2);
	else if (opp == '*')
		printf("%d\n", n1 * n2);
	else if (opp == '/' && n2 != 0)
		printf("%d\n", n1 / n2);
	else if (opp == '%' && n2 != 0)
		printf("%d\n", n1 % n2);
	else
		printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc == 4 && is_opp(argv[2][0])
				&& contains_digit(argv[1]) && contains_digit(argv[3]))
		solve_op(atoi(argv[1]), argv[2][0], atoi(argv[3]));
	else
		printf("\n");
	return (0);
}
