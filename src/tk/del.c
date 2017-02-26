/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:52:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 12:31:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Watch out for double-free when freeing tokens then freeing redirections!
*/

void	tk_del(t_token *tk)
{
	t_token	*tmp;

	while (tk != NULL)
	{
		tmp = tk->next;
		free(tk->val);
		free(tk);
		tk = tmp;
	}
}
