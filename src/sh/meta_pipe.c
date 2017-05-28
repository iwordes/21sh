/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 20:23:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/28 13:31:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define D(N) ps->exe[i + N].fd[!N]

bool	sh_meta_pipe(t_ps *ps, uint32_t i)
{
	int			p[2];

	while (i < ps->exe_len && ps->exe[i].pipe)
	{
		if (pipe(p))
			return (false);
		if (D(0) > 2)
			close(D(0));
		if (D(1) > 2)
			close(D(1));
		D(0) = p[1];
		D(1) = p[0];
		i += 1;

		ft_printf("  %u \e[92m|\e[0m %u\n", i, i + 1);
	}
	return (true);
}
