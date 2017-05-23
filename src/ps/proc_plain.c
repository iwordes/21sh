/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_plain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:26:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/22 14:26:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define TK ps->tk[i + *t]
#define EXE ps->exe[ps->exe_len]
#define ARG EXE.argv[EXE.argv_len]
#define TK_VAL (TK.type <= 1 && (i == 0 || (TK.flag & TKF_ADJ)))


bool	ps_proc_plain(t_ps *ps, uint32_t *t)
{
	uint32_t	len;
	uint32_t	i;

	i = 0;
	len = 0;
	while (i + *t < ps->tk_len && TK_VAL)
	{
		len += ft_strlen(TK.str);
		i += 1;
	}
	while (EXE.argv_len + 2 >= EXE.argv_mem)
	{
		if (DRALT(EXE.argv, char*, EXE.argv_mem * 2, EXE.argv_mem) == NULL)
			PSFAIL("Could not grow argv.");
		bzero(EXE.argv + EXE.argv_mem, sizeof(char*) * EXE.argv_mem);
		EXE.argv_mem *= 2;
	}
	i = 0;
	if ((ARG = ZALT(char, len + 1)) == NULL)
		PSFAIL("Could not allocate space for argument.");
	while (i + *t < ps->tk_len && TK_VAL)
	{
		ft_strcat(ARG, TK.str);
		i += 1;
	}
	*t += i;
	EXE.argv_len += 1;
	return (true);
}
