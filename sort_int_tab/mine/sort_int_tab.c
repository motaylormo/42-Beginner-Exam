/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:38:51 by exam              #+#    #+#             */
/*   Updated: 2019/01/08 11:50:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int rounds = 0;
	unsigned int i;
	int tmp;

	while (rounds < size)
	{
		i = 1;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
			}
			i++;
		}
		rounds++;
	}
}
