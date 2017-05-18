/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:51:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/17 14:59:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	loop(void)
{
	char	*in;
	t_ps	ps;

	while ((in = input()))
	{
		ft_printf("\e[1;93m:\e[0m \e[92m\"%s\"\e[0m\n", in);
		if (parse(&ps, in))
		{
			for (uint32_t i = 0; i < ps.tk_len; i += 1)
				ft_printf("\e[1;92m:\e[0;1m {\e[0m \e[92m\"%s\"\e[0m, %u, %u \e[1m}\e[0m\n", ps.tk[i].str, ps.tk[i].flag, ps.tk[i].type);
			write(1, "\n", 1);
			// shell(&ps);
		}
		clean(&ps, in);
	}
}
