/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:40:41 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 18:55:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Returns the absolute value of a given input.
*/

uintmax_t	ft_absolute(intmax_t integer)
{
	return (integer >= 0 ? integer : -integer);
}
