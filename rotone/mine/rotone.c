/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:13:24 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 09:20:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

/*
**	Non-alphabetic charaters (like ' ' and '.') are unchanged.
*/
void	rotone(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <='z') || (*str >= 'A' && *str <='Z'))
		{
			if (*str == 'z' || *str == 'Z')
				ft_putchar(*str - 25);
			else
				ft_putchar(*str + 1);
		}
		else
			ft_putchar(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}
