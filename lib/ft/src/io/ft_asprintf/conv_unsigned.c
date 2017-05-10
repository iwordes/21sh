/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unsigned_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 12:01:50 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/27 10:03:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t		ft_asprintf_conv_unsigned(char **string, va_list arg, t_printer *p)
{
	*string = ft_asprintf_uitoa_base(ft_asprintf_cast_unsigned(arg, p), 10, p);
	if (*string == NULL)
		return (-1);
	else
		return (ft_strlen(*string));
}
