/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:16:04 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/21 15:17:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		heredoc(const char *str)
{
	int		fd[2];

	if (pipe(fd) == -1)
		return (-1);
	write(fd[1], str, ft_strlen(str));
	close(fd[1]);
	return (fd[0]);
}
