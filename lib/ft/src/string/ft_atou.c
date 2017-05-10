/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:09:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/11 11:09:38 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned	ft_atou(const char *str)
{
	unsigned	n;

	n = 0;
	ITER(str, ft_isspace(*str));
	while (ft_isdigit(*str))
	{
		n = (n * 10) + (*str - '0');
		str += 1;
	}
	return (n);
}
