/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:40:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/01 20:47:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** NOTE: Using strndup may cause problems because of code added in parse.c
** that applies field width to precision whenzero_pad is on and precision is -1.
*/

ssize_t		ft_asprintf_conv_str(char **string, va_list arg, t_printer *p)
{
	char	*input;

	if ((p->length & 4) != 0)
		return (ft_asprintf_conv_str_long(string, arg, p));
	input = va_arg(arg, char*);
	if (input == NULL)
		input = "(null)";
	if (p->prec >= 0)
		*string = ft_strndup(input, p->prec);
	else
		*string = ft_strdup(input);
	if (*string == NULL)
		return (-1);
	else
		return (ft_strlen(*string));
}
