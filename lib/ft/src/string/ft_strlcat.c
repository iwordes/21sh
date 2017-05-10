/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:30 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Overview
** ========
** Given two strings and a target size, appends up to (size - strlen(string1)
** - 1) characters to the first string.
**
** The return value is ALWAYS THE SAME. However, it has several meanings:
** 1. If it didn't use the entire buffer, the return value is what it used.
** 2. If it used the entire buffer, the return value is the input size.
** 3. If it needed more memory, the return value is the necessary buffer size.
**
** Explanation
** ===========
** 1. If the body's size exceeds the given size, we truncate it to the given.
** 2. While there are characters left to append and there is space in the
**    buffer, we copy more characters to the end of the buffer.
** 3. If there is space remaining, we terminate the end of the buffer.
** 4. Finally, we return the total size of the body and suffix combined.
*/

size_t		ft_strlcat(char *string, const char *suffix, size_t size)
{
	size_t	i;
	size_t	body_length;

	i = 0;
	body_length = ft_strlen(string);
	if (body_length > size)
		body_length = size;
	while (suffix[i] != 0 && body_length + i < size - 1)
	{
		string[body_length + i] = suffix[i];
		i++;
	}
	if (size > 0 && body_length < size)
		string[body_length + i] = 0;
	return (body_length + ft_strlen(suffix));
}
