/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:23:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 19:38:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Return the given integer in binary notation.
*/

ssize_t		ft_asprintf_conv_binary(char **string, va_list arg, t_printer *p)
{
	*string = ft_asprintf_uitoa_base(ft_asprintf_cast_unsigned(arg, p), 2, p);
	if (*string == NULL)
		return (-1);
	return (ft_strlen(*string));
}
