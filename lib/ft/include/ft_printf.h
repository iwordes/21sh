/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:11:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 13:50:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Added: 1.3.0
*/

# include <stdarg.h>
# include <sys/types.h>

# include "ft_printf_internal.h"

int		ft_printf(const char *fmt, ...);
int		ft_asprintf(char **line, const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_eprintf(const char *fmt, ...);

int		ft_vprintf(const char *fmt, va_list args);
int		ft_vasprintf(char **line, const char *fmt, va_list args);
int		ft_vdprintf(int fd, const char *fmt, va_list args);

#endif
