/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:48:50 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:11:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Prints a given integer, in base-10 (decimal), to stdout.
*/

void	ft_putint(intmax_t integer)
{
	ft_putint_base_fd(integer, 10, 1);
}
