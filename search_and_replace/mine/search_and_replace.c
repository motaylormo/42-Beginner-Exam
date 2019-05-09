/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:38:07 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 09:42:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
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

void	search_and_replace(char *str, char find, char replacement)
{
	while (*str)
	{
		if (*str == find)
			ft_putchar(replacement);
		else
			ft_putchar(*str);
		str++;
	}
}

/*
**	If argv[2] and argv[3] are both only a single char
*/
int		main(int argc, char **argv)
{
	if (argc == 4 && ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
	ft_putchar('\n');
	return (0);
}
