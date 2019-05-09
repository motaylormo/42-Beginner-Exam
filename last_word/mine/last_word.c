/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:12:06 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 09:16:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define WHITESPACE(c) (c == ' ' || c == '\t')

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
**	Start at the end of the string.
**	Rewind through any extra whitespace at the end,
**		then rewind until you hit whitespace again (aka through 1 word).
**	From there, print the word.
*/
void	last_word(char *str)
{
	int i = ft_strlen(str) - 1;

	while (i >= 0 && WHITESPACE(str[i]))
		i--;
	while (i - 1 >= 0 && !WHITESPACE(str[i - 1]))
		i--;
	while (str[i] && !WHITESPACE(str[i]))
		ft_putchar(str[i++]);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	ft_putchar('\n');
	return (0);
}
