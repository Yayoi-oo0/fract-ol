/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:26:37 by oyayoi            #+#    #+#             */
/*   Updated: 2024/07/14 19:25:58 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	char	a;
	int		count;

	a = 0;
	count = 0;
	if (n < 10)
	{
		a = n + '0';
		write(1, &a, 1);
		count++;
	}
	else
	{
		count += ft_putunbr(n / 10);
		count += ft_putunbr(n % 10);
	}
	return (count);
}
