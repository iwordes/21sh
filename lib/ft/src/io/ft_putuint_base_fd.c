/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:53:50 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:24:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putuint_base_fd_body(uintmax_t i, char base, int fd)
{
	if (i / base != 0)
		ft_putuint_base_fd_body(i / base, base, fd);
	ft_putchar_fd(BASE64[ft_absolute(i % base)], fd);
}

void		ft_putuint_base_fd(uintmax_t integer, char base, int fd)
{
	if (base >= 2 && base <= 64)
		ft_putuint_base_fd_body(integer, base, fd);
}
