/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:38:15 by oyayoi            #+#    #+#             */
/*   Updated: 2024/04/21 16:54:41 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*mem1;
	char	*mem2;
	size_t	i;

	mem1 = (char *)dst;
	mem2 = (char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			mem1[i] = mem2[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			mem1[i - 1] = mem2[i - 1];
			i--;
		}
	}
	return (dst);
}
