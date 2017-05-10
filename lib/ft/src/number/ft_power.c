/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:40 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 18:57:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Returns the given number * itself power times.
** Watch out for overflow!
*/

intmax_t	ft_power(intmax_t base, unsigned exponent)
{
	intmax_t	output;

	if (exponent == 0)
		return (1);
	else
	{
		output = base;
		while (--exponent != 0)
			output *= base;
	}
	return (output);
}
