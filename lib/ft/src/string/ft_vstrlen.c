/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:47:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 21:10:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_vstrlen_(const char *str, va_list args)
{
	size_t	i;
	size_t	l;

	if (str == NULL)
		return (0);
	l = ft_strlen(str);
	while ((str = va_arg(args, char*)) != NULL)
	{
		i = 0;
		while (str[i] != 0)
			i += 1;
		l += i;
	}
	return (l);
}

/*
** Get the combined length of several strings.
*/

size_t	ft_vstrlen(const char *str, ...)
{
	va_list	args;
	size_t	l;

	va_start(args, str);
	l = ft_vstrlen_(str, args);
	va_end(args);
	return (l);
}
