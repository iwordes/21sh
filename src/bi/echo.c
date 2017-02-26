/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:22:15 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/02 16:06:36 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** echo adds special parsing for escape sequences like "\n" or "\t".
*/

static void	e_print(const char *str)
{
	size_t	l;

	while (*str != 0)
	{
		l = ft_struntil(str, '\\');
		write(1, str, l);
		if (*(str += l) == 0)
			break ;
		if (str[1] == 'e')
			write(1, "\e", 1);
		else if (str[1] == 'n')
			write(1, "\n", 1);
		else if (str[1] == 't')
			write(1, "\t", 1);
		else if (str[1] == 'r')
			write(1, "\r", 1);
		else
			write(1, str, 2);
		str += 2;
	}
}

int		bi_echo(char **argv)
{
	bool	nl;
	size_t	i;

	i = 1;
	nl = true;
	if (argv[1] != NULL && ft_strequ(argv[1], "-n"))
	{
		nl = false;
		i += 1;
	}
	if (argv[i] != NULL)
		e_print(argv[i++]);
	while (argv[i] != NULL)
	{
		write(1, " ", 1);
		e_print(argv[i++]);
	}
	if (nl)
		write(1, "\n", 1);
	return (0);
}
