/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 13:25:15 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/16 13:25:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_atol(const char *str)
{
	int		sign;
	long	n;

	n = 0;
	sign = 1;
	ITER(str, ft_isspace(*str));
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str += 1;
	while (ft_isdigit(*str))
	{
		n = (n * 10) + (*str - '0');
		str += 1;
	}
	return (n * sign);
}
