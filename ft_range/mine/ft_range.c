/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:44:36 by exam              #+#    #+#             */
/*   Updated: 2019/01/29 09:54:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int	len = 1 + ((start > end) ? start - end : end - start);
	int	*tab;

	tab = (int*)malloc(sizeof(len));
	for (int i = 0; i < len; ++i)
	{
		tab[i] = start;
		start = (start < end) ? start + 1 : start - 1;
	}
	return (tab);
}
