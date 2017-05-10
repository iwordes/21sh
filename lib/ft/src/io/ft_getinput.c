/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:28:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/11 12:34:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Return one line from stdinput.
*/

char	*ft_getinput(const char *prompt)
{
	char	*line;

	ft_putstr(prompt);
	ft_getline(0, &line);
	return (line);
}
