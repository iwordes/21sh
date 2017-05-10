/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:19 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strequ(const char *string1, const char *string2)
{
	if (string1 != NULL && string2 != NULL)
		return (!ft_strcmp(string1, string2));
	else
		return (0);
}
