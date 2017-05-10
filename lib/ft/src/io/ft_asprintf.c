/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:20:38 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 09:06:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_asprintf(char **string, const char *fmt, ...)
{
	va_list	args;
	int		ret;

	va_start(args, fmt);
	ret = ft_vasprintf(string, fmt, args);
	va_end(args);
	return (ret);
}
