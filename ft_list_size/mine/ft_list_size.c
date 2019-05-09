/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:25:23 by exam              #+#    #+#             */
/*   Updated: 2019/01/22 09:37:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	int	size = 1;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}
