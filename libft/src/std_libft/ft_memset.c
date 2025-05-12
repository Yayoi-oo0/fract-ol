/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:05:00 by oyayoi            #+#    #+#             */
/*   Updated: 2024/04/17 20:37:58 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}

// int	main(void)
// {
// 	char buf[] = "123456789";

// 	printf("ft_memset:%s\n", ft_memset(buf, 'a', 5));
// 	printf("memset:%s\n", memset(buf, 'a', 5));
// 	return (0);
// }
