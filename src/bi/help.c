/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 08:47:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 08:59:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define HL1 "\e[1mecho \e[0;3mtext\e[0m ...\n"
#define HL2 "\e[1mexit\e[0m\n"
#define HL4 ""
#define HL HL1 HL2 HL4

int		bi_help(char **argv)
{
	ft_putstr(HL);
	(void)argv;
	return (0);
}
