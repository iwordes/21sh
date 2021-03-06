/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:12:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 12:33:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	sh_exit(char **argv, int argc)
{
	if (argc == 1)
	{
		uninit();
		exit(0);
	}
	(void)argv;
}
