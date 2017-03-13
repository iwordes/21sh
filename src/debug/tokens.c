/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 11:48:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 19:43:38 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	debug_tokens(t_token *tk)
{
	ft_printf("\e[93mTokens:\e[0m\n");
	while (tk != NULL)
	{
		ft_printf("{\n");
		ft_printf("    \"type\": \"%s\"\n", debug_type(tk->type));
		ft_printf("    \"adj\":  %v\n", (tk->adj) ? "true" : "false");
		if (tk->type != TK_REDIR)
			ft_printf("    \"val\":  \"%s\"\n", tk->val);
		ft_printf("}%s\n", (tk->next != NULL) ? "," : "");
		tk = tk->next;
	}
}
