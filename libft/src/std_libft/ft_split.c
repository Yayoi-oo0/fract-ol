/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:04:44 by oyayoi            #+#    #+#             */
/*   Updated: 2024/05/26 20:09:10 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_of_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_splitstore(char const *s, char c, char **str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (s[++i])
	{
		if (s[i] != c && s[i])
		{
			j = 0;
			j = ft_wordlen(&s[i], c);
			str[k] = ft_substr(s, i, j);
			if (!str[k])
			{
				ft_free(str);
				return (NULL);
			}
			i += (j - 1);
			k++;
		}
	}
	str[k] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		wordnumber;
	char	**str;

	wordnumber = 0;
	if (!s)
		return (NULL);
	wordnumber = ft_number_of_wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (wordnumber + 1));
	if (!str)
		return (NULL);
	str = ft_splitstore(s, c, str);
	return (str);
}
