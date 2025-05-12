/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:21:05 by oyayoi            #+#    #+#             */
/*   Updated: 2025/01/15 13:44:07 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	num;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (sign == -1 && num > ((unsigned long)LONG_MIN - (*str - '0')) / 10)
			return ((int)LONG_MIN);
		if (sign == 1 && num > ((unsigned long)LONG_MAX - (*str - '0')) / 10)
			return ((int)LONG_MAX);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
