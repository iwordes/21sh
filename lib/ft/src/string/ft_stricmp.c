/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stricmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:09:04 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/21 20:05:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define ICMP_1(C1, C2) (ft_islower(C1) && C2 == (C1 - 32))
#define ICMP_2(C1, C2) (ft_isupper(C1) && C2 == (C1 + 32))
#define ICMP(C1, C2) ((C1 == C2) || ICMP_1(C1, C2) || ICMP_2(C1, C2))

/*
** Compare two strings, case insensitive.
*/

int		ft_stricmp(const char *str1, const char *str2)
{
	if (str1 == str2)
		return (0);
	while (ICMP(*str1, *str2))
	{
		if (*str1 == 0)
			return (0);
		str1 += 1;
		str2 += 1;
	}
	return ((uint8_t)(*str1) - (uint8_t)(*str2));
}
