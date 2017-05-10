/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:31:29 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/01 16:39:15 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t	ft_asprintf_conv_ptr(char **string, va_list arg, t_printer *p)
{
	uintmax_t	ptr;

	p->alt = TRUE;
	if ((ptr = va_arg(arg, uintmax_t)) == 0 && p->prec == 0)
		*string = ft_strdup("0x");
	else
		*string = ft_asprintf_uitoa_base(ptr, 16, p);
	if (*string == NULL)
		return (-1);
	if (!(p->zero_pad && p->width > 0))
		(*string)[1] = 'x';
	return (ft_strlen(*string));
}
