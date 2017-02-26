/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 11:48:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 12:31:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	debug_tokens(t_token *tk)
{
	while (tk != NULL)
	{
		ft_printf("{\n");
		ft_printf("    \"type\": %u\n", tk->type);
		ft_printf("    \"adj\":  %v\n", (tk->adj) ? "true" : "false");
		if (tk->type != TK_REDIR)
			ft_printf("    \"val\":  \"%s\"\n", tk->val);
		ft_printf("}\n");
		tk = tk->next;
	}
}
