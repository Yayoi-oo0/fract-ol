/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:27:34 by oyayoi            #+#    #+#             */
/*   Updated: 2024/05/07 22:41:54 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
		size_t dstsize)
{
	size_t	i;
	size_t	copy;
	size_t	d_nb;
	size_t	s_nb;

	s_nb = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s_nb);
	d_nb = ft_strlen(dst);
	if (d_nb >= dstsize)
		return (dstsize + s_nb);
	copy = dstsize - d_nb - 1;
	i = 0;
	while (i < copy && src[i] != '\0')
	{
		dst[d_nb + i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i + d_nb] = '\0';
	return (s_nb + d_nb);
}
