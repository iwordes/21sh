/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:37:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/01 13:41:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t		ft_asprintf_conv_octal(char **string, va_list arg, t_printer *p)
{
	uintmax_t	integer;

	integer = ft_asprintf_cast_unsigned(arg, p);
	if (integer == 0 && p->prec == 0 && p->alt)
		*string = ft_strdup("0");
	else
		*string = ft_asprintf_uitoa_base(integer, 8, p);
	if (*string == NULL)
		return (-1);
	else
		return (ft_strlen(*string));
}
