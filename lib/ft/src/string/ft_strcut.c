/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:02:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 09:12:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Remove some portion of a string.
** st must be an index no greater than the length of the string. Otherwise,
** undefined behavior may occur.
*/

char	*ft_strcut(char *str, size_t i, size_t n)
{
	while (str[i + n] != 0)
	{
		str[i] = str[i + n];
		i += 1;
	}
	ft_memset(str + i, 0, ft_strlen(str + i));
	return (str);
}
