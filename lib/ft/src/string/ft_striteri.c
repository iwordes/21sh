/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:23 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_striteri(char *string, void (*func)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (string != NULL && func != NULL)
		while (string[i])
		{
			func(i, string + i);
			i++;
		}
}
