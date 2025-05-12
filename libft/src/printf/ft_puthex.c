/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:27:06 by oyayoi            #+#    #+#             */
/*   Updated: 2024/08/05 00:33:52 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int upper)
{
	char	*str;
	int		count;

	str = ft_itoa_base(n, upper);
	if (!str)
		return (0);
	count = ft_putstr(str);
	free(str);
	return (count);
}
