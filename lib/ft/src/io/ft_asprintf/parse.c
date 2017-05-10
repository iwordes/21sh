/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:42:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/15 13:50:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Parsing loops through the stages prior to a conversion until all stages fail.
** After that, parsing ends, and the conversion-or-not is set as this
** t_printer's conversion.
**
** 1. Increment our place in the format string, moving past a '%'.
** 2. Loop through the stages of parsing until all of them fail.
** 3. Handle a negative width given by '*'.
** 4. If the left-justify flag is set or both a precision is set and the
**    conversion is numeric, disable the zero-pad flag.
** 5. Advance past the chosen conversion.
*/

void	ft_asprintf_parse(const char **fmt, va_list arg, t_printer *printer)
{
	*fmt += 1;
	while (ft_asprintf_parse_wargp(fmt, arg, printer)
		|| ft_asprintf_parse_flags(fmt, printer)
		|| ft_asprintf_parse_length(fmt, printer))
		(void)0;
	if ((printer->conv = **fmt) == 0)
		return ;
	if (printer->width < 0)
	{
		printer->width *= -1;
		printer->left_just = TRUE;
	}
	if (printer->left_just || (PF_NUM(printer->conv) && printer->prec >= 0))
		printer->zero_pad = FALSE;
	*fmt += 1;
}
