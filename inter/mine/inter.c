/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:54:45 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 10:08:56 by exam             ###   ########.fr       */
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

int		ft_strchr(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

/*
**	In order to avoid doubles of the same letter,
**		I keep an array of each letter I've already used.
*/
void	inter(char *s1, char *s2)
{
	int	s1_len = ft_strlen(s1);
	char already[s1_len];
	for (int i = 0; i < s1_len; i++)
		already[i] = '\0';

	int a = 0;
	while (*s1 && *s2)
	{
		if (ft_strchr(*s1, s2) && !ft_strchr(*s1, already))
		{
			ft_putchar(*s1);
			already[a++] = (*s1);
		}
		s1++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
