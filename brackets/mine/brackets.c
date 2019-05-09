/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:53:30 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 12:13:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	brackets(char *str)
{
	int	round = 0;
	int	square = 0;
	int	curvy = 0;

	int	len = ft_strlen(str);
	char	next[len + 1];
	int		i = 0;

	while (*str)
	{
		if (*str == '(')
			round++;
		if (*str == '[')
			square++;
		if (*str == '{')
			curvy++;
		if (*str == '(' || *str == '[' || *str == '{')
		{
			i++;
			next[i] = *str;
		}

		if ((*str == ')' && round == 0) ||
				(*str == ']' && square == 0) ||
				(*str == '}' && curvy == 0))
		{
			ft_putstr("Error\n");
			return ;
		}
		
		if (*str == ')' && next[i] == '(')
			round--;
		if (*str == ']' && next[i] == '[')
			square--;
		if (*str == '}' && next[i] == '{')
			curvy--;
		if (*str == ')' || *str == ']' || *str == '}')
			i--;
		str++;
	}
	
	if (round == 0 && square == 0 && curvy == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("Error\n");
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			brackets(argv[i]);
	}
	else
		ft_putstr("\n");
	return (0);
}
