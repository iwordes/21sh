/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:04:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 12:31:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define VAL_CHR(C) (!ft_isspace(C) && C != '\'' && C != '\"')

static size_t	len_(const char *str)
{
	size_t	i;
	size_t	l;

	l = 0;
	i = ~0;
	while (str[i += 1] != 0 && VAL_CHR(str[i]))
	{
		if (str[i] == '\\' && str[i + 1] != '$')
			i += 1;
		l += 1;
	}
	ft_printf("len_: \e[95m%zu\e[0m\n", l);
	return (l);
}

void	lx_str(t_token *tk, const char **str, bool *err)
{
	size_t	i;

	ft_printf("lx_str(\"%s\")\n", *str);
	i = 0;
	tk->type = TK_STR;
	MGUARD(tk->val = MALT(char, len_(*str) + 1));
	while ((*str)[i] != 0 && VAL_CHR((*str)[i]))
	{
		if (**str == '\\')
		{
			*str += 1;
			if ((*str)[i] == 0)
				break ;
		}
		tk->val[i] = (*str)[i];
		i += 1;
	}
	tk->val[i] = 0;
	*str += i;
	(void)err;
}
