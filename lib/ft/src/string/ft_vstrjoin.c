/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:20:55 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 21:09:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Performance considerations:
** - ft_strnew zeroes out all available memory. While it may complicate the
**   internal copying logic, it may be wise to forego it in favor of malloc.
*/

char	*ft_vstrjoin_(const char *current, va_list args)
{
	va_list		largs;
	char		*str;

	NULL_GUARD(current);
	va_copy(largs, args);
	str = ft_strnew(ft_vstrlen_(current, largs) + 1);
	va_end(largs);
	NULL_GUARD(str);
	ft_strcat(str, current);
	while ((current = va_arg(args, char*)) != NULL)
		ft_strcat(str, current);
	return (str);
}

/*
** Join together multiple strings. ft_vstrjoin is faster with more joins, as
** allocation is done only once, and all strings are then copied to the new
** string at once.
** The last argument must be NULL.
*/

char	*ft_vstrjoin(const char *current, ...)
{
	va_list		args;
	char		*str;

	va_start(args, current);
	str = ft_vstrjoin_(current, args);
	va_end(args);
	return (str);
}
