/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:46 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strnequ(const char *string1, const char *string2, size_t n)
{
	if (string1 != NULL && string2 != NULL)
		return (ft_strncmp(string1, string2, n) == 0);
	else if (string1 == string2)
		return (1);
	else
		return (0);
}
