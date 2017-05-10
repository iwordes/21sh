/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:44:18 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:00:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTF_H
# define FT_UTF_H

# include <stdint.h>
# include "ft_string.h"

/*
** ASCII:        0b0xxxxxxx
** Continuation: 0b10xxxxxx
** Header (2B):  0b110xxxxx
** Header (3B):  0b1110xxxx
** Header (4B):  0b11110xxx
*/
# define IS_UTF8_ASCII(B) ((B) >= 0 && (B) <= 127)
# define IS_UTF8_CONT(B) ((B) >= 128 && (B) <= 191)
# define IS_UTF8_H2(B) ((B) >= 192 && (B) <= 223)
# define IS_UTF8_H3(B) ((B) >= 224 && (B) <= 239)
# define IS_UTF8_H4(B) ((B) >= 240 && (B) <= 247)
# define IS_UTF8_HEAD(B) (IS_UTF8_H2(B) || IS_UTF8_H3(B) || IS_UTF8_H4(B))
# define IS_UTF8(B) (IS_UTF8_HEAD(B) || IS_UTF8_CONT(B) || IS_UTF8_ASCII(B))

/*
** High Surrogate: 0b110110xx xxxxxxxx
** Low Surrogate:  0b110111xx xxxxxxxx
*/
# define IS_UTF16_SH(S) ((S) >= 0xD800 && (S) < 0xDC00)
# define IS_UTF16_SL(S) ((S) >= 0xDC00 && (S) <= 0xDFFF)
# define IS_UTF16_SURG(S) (IS_UTF16_SH(S) || IS_UTF16_SL(S))
# define IS_UTF16(S) (IS_UTF16_SURG(S) || (!IS_UTF16_SURG(S) && (S) <= 0xFFFF))

uint32_t	ft_utf8_decode(const uint8_t *utf8);
uint32_t	ft_utf8_encode(uint32_t utf32);
int			ft_utf8_size(const uint8_t *utf8);

uint16_t	*ft_utf8to16(const uint8_t *utf8);
size_t		ft_utf8to16_len(const uint8_t *utf8);

uint32_t	ft_utf16_decode(const uint16_t *utf16);
uint32_t	ft_utf16_encode(uint32_t utf32);

uint8_t		*ft_utf16to8(const uint16_t *utf16);
size_t		ft_utf16to8_len(const uint16_t *utf16);

uint8_t		*ft_utf32to8(const uint32_t *utf32);
size_t		ft_utf32to8_len(const uint32_t *utf32);

#endif
