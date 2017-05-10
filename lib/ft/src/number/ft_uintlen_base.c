/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:05:26 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 17:07:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_uintlen_base(uintmax_t integer, char base)
{
	int	length;

	if (base > 1)
	{
		length = 1;
		while ((integer /= base) != 0)
			length++;
		return (length);
	}
	if (base == 1)
		return (integer);
	return (0);
}
