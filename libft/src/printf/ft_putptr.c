/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:25:37 by oyayoi            #+#    #+#             */
/*   Updated: 2024/08/11 20:33:48 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long n)
{
	char	*str;
	int		count;

	if (n == 0)
		return (ft_putstr("(nil)"));
	str = ft_itoa_base(n, 0);
	if (!str)
		return (0);
	count = ft_putstr("0x");
	count += ft_putstr(str);
	free(str);
	return (count);
}
