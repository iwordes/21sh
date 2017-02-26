/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:04:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/06 14:44:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtm.h>

/*
** Initialize termcap, if possible.
*/

int		tm_init(void)
{
	extern char	**environ;
	char		*tcbuff;
	size_t		i;

	if ((tcbuff = (char*)malloc(2048)) == NULL)
		return (0);
	i = ~0L;
	while (environ[i += 1] != NULL)
		if (ft_strnequ(environ[i], "TERM") && environ[i][4] == '=')
		{
			if (tgetent(tcbuff, environ[i] + 5) > 0)
				return (1);
			break ;
		}
	free(tcbuff);
	return (0);
}
