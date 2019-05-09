/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:24:38 by exam              #+#    #+#             */
/*   Updated: 2019/01/15 12:08:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checkmate.h"

int		ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		checkmate(char **board)
{
	int	size = ft_strlen(board[1]);

	for (int x = 1; x <= size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (check_piece(x, y, board, size))
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (checkmate(argv))
			ft_putstr("Success");
		else
			ft_putstr("Fail");
	}
	ft_putstr("\n");
	return (0);
}
