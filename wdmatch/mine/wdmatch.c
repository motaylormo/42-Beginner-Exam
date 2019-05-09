/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:12:31 by exam              #+#    #+#             */
/*   Updated: 2019/01/22 09:21:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strchr(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

int		wdmatch(char *s1, char *s2)
{
	while (*s1)
	{
		if (!(s2 = ft_strchr(*s1, s2)))
			return (0);
		s1++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 3 && wdmatch(argv[1], argv[2]))
		ft_putstr(argv[1]);
	ft_putstr("\n");
	return (0);
}
