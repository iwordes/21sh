/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:54:30 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 18:56:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_intlen(intmax_t integer)
{
	int		length;

	length = (integer < 0) ? 2 : 1;
	while ((integer /= 10) != 0)
		length++;
	return (length);
}
