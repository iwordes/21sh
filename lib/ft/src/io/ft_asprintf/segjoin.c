/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 19:37:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/02 17:09:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** An asprintf-custom function for accurately joining two asprintf segments.
*/

char	*ft_asprintf_segjoin(char *text, char *conv, ssize_t tl, ssize_t cl)
{
	char	*string;

	NULL_GUARD(string = ft_strnew(tl + cl));
	ft_memcpy(string, text, tl);
	ft_memcpy(string + tl, conv, cl);
	return (string);
}
