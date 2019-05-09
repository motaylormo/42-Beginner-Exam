/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:29:17 by exam              #+#    #+#             */
/*   Updated: 2019/01/15 12:19:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkmate.h"

static int		is_piece(char c)
{
	if (c == 'P' || c == 'B' || c == 'R' || c == 'Q')
		return (1);
	return (0);
}

static int	check_spot(int x, int y, char **board, int size)
{
	if (!(x >= 1 && x <= size))
		return (-1);
	if (!(y >= 0 && y < size))
		return (-1);
	if (is_piece(board[x][y]))
		return (-1);
	if (board[x][y] == 'K')
		return (2);
	return (0);
}

static int	pawn(int x, int y, char **board, int size)
{
	if (check_spot(x - 1, y + 1, board, size) == 2)
		return (1);
	if (check_spot(x - 1, y - 1, board, size) == 2)
		return (1);
	return (0);
}

static int	bishop(int x, int y, char **board, int size)
{
	int ix = x - 1;
	int iy = y - 1;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		ix--;
		iy--;
	}
	ix = x + 1;
	iy = y + 1;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		ix++;
		iy++;
	}
	ix = x + 1;
	iy = y - 1;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		ix++;
		iy--;
	}
	ix = x - 1;
	iy = y + 1;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		ix--;
		iy++;
	}
	return (0);
}

static int	rook(int x, int y, char **board, int size)
{
	int ix = x - 1;
	int iy = y;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		ix--;
	}
	ix = x + 1;
	iy = y;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		ix++;
	}
	ix = x;
	iy = y - 1;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		iy--;
	}
	ix = x;
	iy = y + 1;
	while (check_spot(ix, iy, board, size) != -1)
	{
		if (check_spot(ix, iy, board, size) == 2)
			return (1);
		iy++;
	}
	return (0);
}

static int	queen(int x, int y, char **board, int size)
{
	if (rook(x, y, board, size) == 1)
		return (1);
	if (bishop(x, y, board, size) == 1)
		return (1);
	return (0);
}

int	check_piece(int x, int y, char **board, int size)
{
	char	piece = board[x][y];

	if (piece == 'P')
		return (pawn(x, y, board, size));
	if (piece == 'B')
		return (bishop(x, y, board, size));
	if (piece == 'R')
		return (rook(x, y, board, size));
	if (piece == 'Q')
		return (queen(x, y, board, size));
	return (0);
}
