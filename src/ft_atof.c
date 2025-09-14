/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:02:34 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/09/14 18:00:22 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	frag_parse_int(double *number, char **p);
static void	frag_parse_fraction(double *number, char **p, int *e);
static void	handle_error(void);
static int	frag_parse_sign(char **p);

double	ft_atof(char *str)
{
	double	number;
	int		e;
	char	*p;
	int		negative;

	number = 0.0;
	e = 0;
	negative = 0;

	p = (char *)str;
	while (*p == ' ' || (*p >= '\t' && *p <= '\r'))
		p++;
	negative = frag_parse_sign(&p);
	frag_parse_int(&number, &p);
	frag_parse_fraction(&number, &p, &e);
	if (*p != '\0')
		handle_error();
	while (e < 0)
	{
		number *= 0.1;
		e++;
	}
	if (negative)
		number = -number;
	return (number);
}

static int	frag_parse_sign(char **p)
{
	int	neg;

	neg = 0;
	if (**p == '-' && ft_strlen(*p) != 1)
	{
		if (**p == '-')
			neg = 1;
		(*p)++;
		if (!ft_isdigit(**p))
			handle_error();
	}
	return (neg);
}

static	void	frag_parse_int(double *number, char **p)
{
	int	digit;

	digit = 0;
	if (!(ft_isdigit(**p)))
		handle_error();
	if (**p == '0')
	{
		(*p)++;
		if (ft_isdigit(**p))
			handle_error();
	}
	while (ft_isdigit(**p) && digit < 18)
	{
		*number = *number * 10.0 + (**p - '0');
		(*p)++;
		digit++;
	}
}

static void	frag_parse_fraction(double *number, char **p, int *e)
{
	int	digit;

	digit = 0;
	if (**p == '.' && ft_strlen(*p) > 1)
	{
		(*p)++;
		while (ft_isdigit(**p) && digit < 18)
		{
			*number = *number * 10.0 + (**p - '0');
			(*p)++;
			(*e)--;
			digit++;
		}
	}
}

static void	handle_error(void)
{
	ft_putstr_fd("Error: Example: ./fractol julia -0.2 0.2\n", 2);
	exit(EXIT_FAILURE);
}
