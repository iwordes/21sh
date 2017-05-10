/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:10:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/11 12:39:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE_H
# define FT_GETLINE_H

/*
** Added: 1.2.0
*/

typedef struct		s_getln
{
	int				fd;
	ssize_t			index;
	ssize_t			limit;
	char			buffer[4096];
	struct s_getln	*next;
}					t_getln;

ssize_t				ft_getline(const int fd, char **const line);
char				*ft_getinput(const char *prompt);

#endif
