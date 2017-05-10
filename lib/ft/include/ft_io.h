/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:38:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 15:01:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdarg.h>
# include "ft_string.h"

/*
** Header for I/O functions, such as printing to the screen, getting input, or
** reading from/writing to a file.
*/

/*
** Output
*/
void	ft_putchar(char c);
void	ft_putendl(const char *string);
void	ft_putint(intmax_t integer);
void	ft_putint_base(intmax_t integer, char base);
void	ft_putstr(const char *string);
void	ft_putuint(uintmax_t integer);
void	ft_putuint_base(uintmax_t integer, char base);

void	ft_putvis(const char *str);
void	ft_puterr(const char *error);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *string, int fd);
void	ft_putflt_fd(long double number, int fd);
void	ft_putint_fd(intmax_t integer, int fd);
void	ft_putint_base_fd(intmax_t integer, char base, int fd);
void	ft_putstr_fd(const char *string, int fd);
void	ft_putuint_fd(uintmax_t integer, int fd);
void	ft_putuint_base_fd(uintmax_t integer, char base, int fd);

/*
** Deprecated
*/
void	ft_putnbr(int integer);
void	ft_putnbr_fd(int integer, int fd);

char	*ft_read(int fd);
int		ft_readln(int fd, char **const line);

#endif
