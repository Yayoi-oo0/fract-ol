/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:46:43 by oyayoi            #+#    #+#             */
/*   Updated: 2024/04/23 17:15:17 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	if (dst == NULL && src == NULL)
		return (dst);
	cpy1 = (unsigned char *)dst;
	cpy2 = (unsigned char *)src;
	while (n)
	{
		*cpy1 = *cpy2;
		cpy1++;
		cpy2++;
		n--;
	}
	return (dst);
}
