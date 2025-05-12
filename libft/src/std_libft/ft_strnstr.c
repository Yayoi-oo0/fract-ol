/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:49:13 by oyayoi            #+#    #+#             */
/*   Updated: 2024/04/27 12:20:17 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*s1;
	const char	*s2;
	size_t		needle_len;

	if (!*needle)
		return ((char *)haystack);
	s1 = haystack;
	s2 = needle;
	needle_len = ft_strlen(needle);
	if (len == 0)
		return (0);
	while (*s1 && len >= needle_len)
	{
		if ((*s1 == *s2) && ft_strncmp(s1, s2, needle_len) == 0)
			return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
