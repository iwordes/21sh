/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:03:15 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 14:33:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Get the size of a UTF-8 sequence in bytes.
*/

int		ft_utf8_size(const uint8_t *utf8)
{
	if (IS_UTF8_ASCII(utf8[0]))
		return (1);
	else if (IS_UTF8_H2(utf8[0]) && IS_UTF8_CONT(utf8[1]))
		return (2);
	else if (IS_UTF8_H3(utf8[0]) && IS_UTF8_CONT(utf8[1])
		&& IS_UTF8_CONT(utf8[2]))
		return (3);
	else if (IS_UTF8_H4(utf8[0]) && IS_UTF8_CONT(utf8[1])
		&& IS_UTF8_CONT(utf8[2]) && IS_UTF8_CONT(utf8[3]))
		return (4);
	else
		return (-1);
}
