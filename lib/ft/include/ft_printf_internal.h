/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:50:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 12:58:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>
# include <wchar.h>

# include <libft.h>

# include "ft_printf.h"

# define PF_DEC_S(X) ((X) == 'd' || (X) == 'D' || (X) == 'i')
# define PF_DEC_U(X) ((X) == 'u' || (X) == 'U')
# define PF_DEC(X) (PF_DEC_S(X) || PF_DEC_U(X))
# define PF_HEX(X) ((X) == 'x' || (X) == 'X')
# define PF_OCT(X) ((X) == 'o' || (X) == 'O')
# define PF_NUM(X) (PF_DEC(X) || PF_HEX(X) || PF_OCT(X))

# define PF_FAILIF(COND) if (COND) return ((l[2] == 0) ? ~0L : -l[2])

typedef struct	s_printer
{
	char		conv;

	char		left_just;
	char		zero_pad;

	char		alt;
	char		base;
	char		group;
	char		sign;
	char		pad;
	char		length;
	char		neg;

	size_t		stars;
	size_t		arg;
	ssize_t		width;
	ssize_t		prec;
}				t_printer;

intmax_t		ft_asprintf_cast_signed(va_list a, t_printer *p);
uintmax_t		ft_asprintf_cast_unsigned(va_list a, t_printer *p);
ssize_t			ft_asprintf_dispatch(char **s, va_list ag, size_t *a,
																t_printer *p);
ssize_t			ft_asprintf_format(char **s, char *r, ssize_t l, t_printer *p);
char			*ft_asprintf_ljust(char *s, char p, size_t tgt, size_t len);
void			ft_asprintf_parse(const char **fmt, va_list arg, t_printer *p);
char			ft_asprintf_parse_flags(const char **fmt, t_printer *p);
char			ft_asprintf_parse_length(const char **fmt, t_printer *p);
char			ft_asprintf_parse_wargp(const char **fmt, va_list arg,
																t_printer *p);
char			*ft_asprintf_rjust(char *s, char p, size_t tgt, size_t len);
char			*ft_asprintf_segdjoin(char *t, char *c, ssize_t lt, ssize_t lc);
char			*ft_asprintf_segjoin(char *t, char *c, ssize_t lt, ssize_t lc);
char			*ft_asprintf_uitoa_base(uintmax_t integer, uint8_t base,
																t_printer *p);

ssize_t			ft_asprintf_conv_char_long(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_dec_long(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_hex_caps(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_octal_long(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_str_long(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_unsigned_long(char **string, va_list arg,
																t_printer *p);

ssize_t			ft_asprintf_conv_binary(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_char(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_dec(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_hex(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_invis(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_octal(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_ptr(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_str(char **s, va_list a, t_printer *p);
ssize_t			ft_asprintf_conv_unsigned(char **s, va_list a, t_printer *p);

ssize_t			ft_asprintf_conv_literal(char **s, va_list a, t_printer *p);

#endif
