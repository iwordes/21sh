/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:53:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 15:54:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_token	*tk_new(void)
{
	t_token	*tk;

	if ((tk = (t_token*)malloc(sizeof(t_token))) != NULL)
	{
		tk->type = ~0;
		tk->adj = false;
		tk->val = NULL;
		tk->next = NULL;
	}
	return (tk);
}
