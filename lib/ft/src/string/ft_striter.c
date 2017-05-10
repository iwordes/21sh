/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:21 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_striter(char *string, void (*func)(char*))
{
	if (string != NULL && func != NULL)
		while (*string)
		{
			func(string);
			string++;
		}
}
