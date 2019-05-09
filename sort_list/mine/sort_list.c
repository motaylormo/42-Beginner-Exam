/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:41:41 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 10:01:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* list, int (*cmp)(int, int))
{
	t_list	*head;
	int		tmp;
	int		sorted;

	head = list;
	while (1)
	{
		list = head;
		sorted = 0;
		while (list && list->next)
		{
			if ((*cmp)(list->data, list->next->data) == 0)
			{
				tmp = list->data;
				list->data = list->next->data;
				list->next->data = tmp;
				sorted++;
			}
			list = list->next;
		}
		if (sorted == 0)
			return (head);
	}
}
