/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:08:11 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:11:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Prints a given integer, in base-10 (decimal), to a given file descriptor.
*/

void	ft_putint_fd(intmax_t integer, int fd)
{
	ft_putint_base_fd(integer, 10, fd);
}
