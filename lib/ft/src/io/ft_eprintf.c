/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:45:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 13:50:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Print to stderr instead of stdout.
*/

int		ft_eprintf(const char *fmt, ...)
{
	va_list		args;
	int			ret;

	va_start(args, fmt);
	ret = ft_vdprintf(2, fmt, args);
	va_end(args);
	return ((ret < 0) ? -1 : ret);
}
