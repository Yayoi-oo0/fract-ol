/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:13:40 by oyayoi            #+#    #+#             */
/*   Updated: 2024/08/09 12:25:38 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countdigit_base(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(unsigned long long n, int upper)
{
	char	*str;
	char	base[16];
	int		i;

	i = 0;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (upper)
	{
		while (i++ < 16)
			base[i] = ft_toupper(base[i]);
	}
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (countdigit_base(n) + 1));
	if (!str)
		return (NULL);
	str[countdigit_base(n)] = '\0';
	while (n != 0)
	{
		str[countdigit_base(n) - 1] = base[n % 16];
		n /= 16;
	}
	return (str);
}
