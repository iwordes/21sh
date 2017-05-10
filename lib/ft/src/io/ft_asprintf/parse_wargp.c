/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wargp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:37:08 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/02 16:07:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Parse a numeric string and apply it to the proper t_printer value.
**
** 1. If the current character is not a valid digit, return immediately.
** 2. Parse the number until no digits remain.
** 3. If the current character is '$', set the current argument to the number
**    as a 1-indexed argument and increment the position in fmt by one.
** 4. If the number came after a dot, set the precision to the number.
** 5. Otherwise, set the width to the number.
*/

static int	parse_num(const char **fmt, char was_dot, t_printer *printer)
{
	ssize_t	num;

	num = 0;
	if ((**fmt >= ((was_dot) ? '0' : '1')) && **fmt <= '9')
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			num = (num * 10) + (**fmt - '0');
			*fmt += 1;
		}
		if (**fmt == '$')
		{
			printer->arg = num - 1;
			*fmt += 1;
		}
		else if (was_dot)
			printer->prec = num;
		else
			printer->width = num;
		return (TRUE);
	}
	return (FALSE);
}

/*
** Apply an argument to the current print job as either width or precision.
**
** 1. If the current character is not a '*', return immediately.
** 2. Store the current argument as an integer.
** 3. Increment the number of '*' encountered in this conversion.
** 4. Increment our location in the format string.
** 5. If the previous character was a dot, set the precision to the number.
** 6. Otherwise, set the width to the number.
** ?. Later, if the width is negative, enable the '-' flag and invert the width.
*/

static int	parse_star(const char **fmt, va_list arg, char dot, t_printer *p)
{
	int		star_num;

	if (**fmt != '*')
		return (FALSE);
	star_num = va_arg(arg, int);
	p->stars += 1;
	*fmt += 1;
	if (dot)
		p->prec = star_num;
	else
		p->width = star_num;
	return (TRUE);
}

/*
** Test for Width, Argument, and Precision, as each could ambiguously turn into
** one another mid-parse.
*/

char		ft_asprintf_parse_wargp(const char **fmt, va_list arg,
															t_printer *printer)
{
	ssize_t		prec;
	char		was_dot;

	prec = 0;
	was_dot = FALSE;
	if (**fmt == '.')
	{
		*fmt += 1;
		was_dot = TRUE;
		printer->prec = 0;
	}
	if (parse_num(fmt, was_dot, printer))
		return (TRUE);
	else if (parse_star(fmt, arg, was_dot, printer))
		return (TRUE);
	return (was_dot);
}
