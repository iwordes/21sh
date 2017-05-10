/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:24:29 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 17:24:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** The mechanics for 0x/0X are applied based on the value of p->conv.
*/

ssize_t	ft_asprintf_conv_hex_caps(char **string, va_list arg, t_printer *p)
{
	return (ft_asprintf_conv_hex(string, arg, p));
}
