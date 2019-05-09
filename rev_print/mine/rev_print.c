/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:06:05 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 09:10:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
**	Remember ft_strlen - 1,
**		because strlen gives the NUMBER of letters,
**		and the letters INDEXES are are 0-indexed.
*/
void	rev_print(char *str)
{
	int i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	ft_putchar('\n');
	return (0);
}
