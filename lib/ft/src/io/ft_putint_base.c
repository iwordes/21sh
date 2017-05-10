/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:02:04 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:24:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Prints a given integer in a given base to stdout.
*/

void	ft_putint_base(intmax_t integer, char base)
{
	ft_putint_base_fd(integer, base, 1);
}
