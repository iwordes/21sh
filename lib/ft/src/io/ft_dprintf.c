/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 09:07:29 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 20:07:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Print a formatted string to a file descriptor.
*/

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	ssize_t	ret;

	va_start(args, fmt);
	ret = ft_vdprintf(fd, fmt, args);
	va_end(args);
	return (ret);
}
