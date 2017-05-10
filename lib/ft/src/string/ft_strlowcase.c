/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:27 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_strlowcase(char *string)
{
	if (string)
		while (*string)
		{
			if (*string >= 'A' && *string <= 'Z')
				*string += 32;
			string++;
		}
}
