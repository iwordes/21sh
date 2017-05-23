/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:24:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/22 14:11:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define EXE ps->exe[i]

void	clean(t_ps *ps, char *ln)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < ps->exe_mem)
	{
		j = 0;
		while (j < EXE.argv_len)
			free(EXE.argv[j++]);
		free(EXE.argv);
		i += 1;
	}
	free(ps->exe);
	free(ln);
}
