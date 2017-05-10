/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 14:23:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/02 12:13:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Apply necessary formatting to the output of a conversion function; e.g.
** minimum field width or the hex "0x" header.
**
** 1. If the width is zero or less, skip reallocation and return immediately.
** 2. If the left-justify flag is set or both the precision is set and the
**    conversion is numeric, perform a right-pad.
**    NOTE: The secondary conditional pair is stubbed out elsewhere in this
**    codebase. Please do not correct it to match this description - I have
**    discovered that it's now always meant to be false.
** 3. Otherwise, perform a left pad with either '0' or ' '.
** 4. If the string failed to allocate, return error.
** 5. If the zero-pad flag is enabled and left-justify is disabled, perform
**    some alternate operations for accurate sign and alt-mark placement.
** 6. Return the greater of the string's length and the minimum field width.
*/

ssize_t	ft_asprintf_format(char **str, char *raw, ssize_t l, t_printer *p)
{
	if (p->width > 0)
	{
		if (p->left_just || (p->prec >= 0 && PF_NUM(p->prec)))
			*str = ft_asprintf_ljust(raw, ' ', p->width, l);
		else
			*str = ft_asprintf_rjust(raw, p->zero_pad ? '0' : ' ', p->width, l);
		free(raw);
		if (*str == NULL)
			return (-1);
		if (p->zero_pad && !p->left_just)
		{
			if (PF_DEC_S(p->conv) && p->neg)
				(*str)[0] = '-';
			else if (PF_DEC_S(p->conv) && (p->sign || p->pad))
				(*str)[0] = (p->sign) ? '+' : ' ';
			if ((p->alt && PF_HEX(p->conv)) || p->conv == 'p')
				(*str)[1] = (p->conv == 'p') ? 'x' : p->conv;
		}
		return (MAX(l, p->width));
	}
	*str = raw;
	return (l);
}
