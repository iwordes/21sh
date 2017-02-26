/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 10:10:46 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 10:11:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** List all shell variables (but not environment variables.)
*/

int		bi_var(char **argv)
{
	var_list();
	(void)argv;
	return (0);
}
