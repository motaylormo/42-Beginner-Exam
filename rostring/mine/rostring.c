/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:22:16 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 10:31:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define WHITESPACE(c) (c == ' ' || c == '\t')

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*skip_whitespace(char *str)
{
	while (WHITESPACE(*str))
		str++;
	return (str);
}

char	*print_word(char *str)
{
	str = skip_whitespace(str);
	while (*str && !WHITESPACE(*str))
	{
		ft_putchar(*str);
		str++;
	}
	str = skip_whitespace(str);
	return (str);
}

char	*skip_first_word(char *str)
{
	str = skip_whitespace(str);
	while (*str && !WHITESPACE(*str))
		str++;
	str = skip_whitespace(str);
	return (str);
}

void	rostring(char *str)
{
	char	*str_head = str;

	str = skip_first_word(str);
	while (*str)
	{
		str = print_word(str);
		ft_putchar(' ');
	}
	print_word(str_head);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	ft_putchar('\n');
	return (0);
}
