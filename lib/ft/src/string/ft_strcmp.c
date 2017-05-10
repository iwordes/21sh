/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 19:17:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	if (str1 == str2)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && str1[i] != 0)
		i += 1;
	return ((unsigned)(str1[i]) - (unsigned)(str2[i]));
}
