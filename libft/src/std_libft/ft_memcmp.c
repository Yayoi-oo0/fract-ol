/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:14:17 by oyayoi            #+#    #+#             */
/*   Updated: 2024/04/24 22:42:02 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	if (!n)
		return (0);
	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	while (n--)
	{
		if (*cmp1 != *cmp2)
			return (*cmp1 - *cmp2);
		if (n)
		{
			cmp1++;
			cmp2++;
		}
	}
	return (0);
}
