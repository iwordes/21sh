/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:53:00 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/15 13:35:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Get the length of the string to allocate.
**
** If "alternate formatting" is enabled, more space will be allocated and
** replaced with zeroes. ('0')
** For alt-hex, one of those zeroes will become 'x'/'X'.
*/

/*
** When precision is specified, the number itself *must* meet the minimum
** number of (in)significant *digits*. When width is specified on its own,
** it simply requires that the whole post-conversion segment meet an N character
** *minimum width*.
*/

/*
** Deducted from precision where possible:
**
** Not deducted from precision:
** Sign/Padding
*/

static size_t	intsize(uintmax_t integer, uint8_t base, t_printer *p)
{
	size_t	l;
	ssize_t	alt_space;

	alt_space = 0;
	l = ft_uintlen_base(integer, base);
	if (p->alt && (base == 8 || base == 16))
	{
		if (p->prec >= 0 && base != 16)
			alt_space -= MAX(p->prec - (ssize_t)l, 0);
		if (base == 16 && (integer > 0 || p->conv == 'p'))
			alt_space += 2;
		else if (base == 8 && integer > 0)
			alt_space += 1;
		alt_space = MAX(alt_space, 0);
	}
	if (p->group && l % 3 == 0)
		l += (l / 3) - 1;
	else if (p->group)
		l += l / 3;
	if (p->prec > 0)
		l = MAX((size_t)p->prec, l);
	if (PF_DEC_S(p->conv) && (p->pad || p->sign))
		l += 1;
	return (l + (size_t)alt_space);
}

/*
** Problem: handling signs in the wrong place. More space only needs to be
** allocated if it might overwrite a significant number. Suggest checking
** if precision > length and adding a byte allocation if so. Likely will need
** a flag to do so accurately.
*/

char			*ft_asprintf_uitoa_base(uintmax_t integer, uint8_t base,
										t_printer *p)
{
	char	*base_string;
	char	*string;
	size_t	i;
	size_t	l;

	if (integer == 0 && p->prec == 0)
		return (ft_strnew(0));
	i = 0;
	l = intsize(integer, base, p);
	NULL_GUARD(string = ft_strnew(l));
	base_string = (p->conv >= 'A' && p->conv <= 'Z') ? BASE64 : BASE64L;
	while (i < l)
	{
		if (p->group && base == 10 && i != l - 1 && i % 4 == 3)
			*(string + (l - 1) - i) = ',';
		else
		{
			*(string + (l - 1) - i) = base_string[integer % base];
			integer /= base;
		}
		i += 1;
	}
	return (string);
}
