/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_literal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:36:52 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/30 10:36:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t	ft_asprintf_conv_literal(char **string, va_list arg, t_printer *p)
{
	(void)arg;
	*string = ft_strnew(1);
	if (*string == NULL)
		return (-1);
	**string = p->conv;
	return (1);
}
