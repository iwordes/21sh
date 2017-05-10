/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:53 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:09:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** In favor of the more accurate ft_putint_fd, this function will not be used.
*/

void	ft_putnbr_fd(int integer, int fd)
{
	ft_putint_fd(integer, fd);
}
