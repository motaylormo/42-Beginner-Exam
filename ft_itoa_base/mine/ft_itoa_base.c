/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:52:16 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 11:17:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	"If base is 10 and value is negative,
**	the resulting string is preceded with a minus sign (-).
**	With any other base, value is always considered unsigned."
*/
static char	*create_str(int value, int base, int *div)
{
	char	*str;
	int		len = (value < 0 && base == 10) ? 2 : 1;

	*div = 1;
	while ((value = value / base))
	{
		len++;
		*div *= base;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	return (str);
}

/*
**	"The base is expressed as an integer, from 2 to 16.
**	The characters comprising the base are the digits from 0 to 9,
**	followed by uppercase letter from A to F."
*/
char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		digit;
	int		div;
	int		i = 0;

	if (!(base >= 2 && base <= 16))
		return (NULL);
	str = create_str(value, base, &div);
	if (value < 0 && base == 10)
		str[i++] = '-';
	while (div >= 1)
	{
		digit = value / div;
		digit = (digit < 0) ? digit * -1 : digit;
		str[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
		value %= div;
		div /= base;
	}
	return (str);
}
