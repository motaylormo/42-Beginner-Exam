/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:11:48 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 10:21:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Start out with the smaller of the two numbers,
**		and keep incrementing it by the same number
**		until finding something that's divisible by both.
**
**	while (a > 0 && b > 0) accounts for
**		"LCM of two non-zero integers..."
**		"If at least one integer is null, LCM is equal to 0."
*/
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;

	lcm = (a < b) ? a : b;
	while (a > 0 && b > 0)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm += (a < b) ? a : b;
	}
	return (0);
}
