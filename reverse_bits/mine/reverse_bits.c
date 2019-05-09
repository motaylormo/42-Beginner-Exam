/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:28:49 by mtaylor           #+#    #+#             */
/*   Updated: 2019/01/07 19:59:53 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	new_oct = 0;

	new_oct += ((octet & 0b10000000) >> 7) << 0;
	new_oct += ((octet & 0b01000000) >> 6) << 1;
	new_oct += ((octet & 0b00100000) >> 5) << 2;
	new_oct += ((octet & 0b00010000) >> 4) << 3;
	new_oct += ((octet & 0b00001000) >> 3) << 4;
	new_oct += ((octet & 0b00000100) >> 2) << 5;
	new_oct += ((octet & 0b00000010) >> 1) << 6;
	new_oct += ((octet & 0b00000001) >> 0) << 7;
	return (new_oct);
}
