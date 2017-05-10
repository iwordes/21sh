/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:38:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/21 13:52:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDEFS_H
# define FT_TYPEDEFS_H

typedef float			t_f32;
typedef double			t_f64;

typedef int8_t			t_i8;
typedef int16_t			t_i16;
typedef int32_t			t_i32;
typedef int64_t			t_i64;

typedef uint8_t			t_u8;
typedef uint16_t		t_u16;
typedef uint32_t		t_u32;
typedef uint64_t		t_u64;

typedef struct			s_2f32
{
	float				x;
	float				y;
}						t_2f32;

typedef struct			s_2f64
{
	double				x;
	double				y;
}						t_2f64;

typedef struct			s_2i8
{
	int8_t				x;
	int8_t				y;
}						t_2i8;

typedef struct			s_2i16
{
	int16_t				x;
	int16_t				y;
}						t_2i16;

typedef struct			s_2i32
{
	int32_t				x;
	int32_t				y;
}						t_2i32;

typedef struct			s_2i64
{
	int64_t				x;
	int64_t				y;
}						t_2i64;

typedef struct			s_2u8
{
	uint8_t				x;
	uint8_t				y;
}						t_2u8;

typedef struct			s_2u16
{
	uint16_t			x;
	uint16_t			y;
}						t_2u16;

typedef struct			s_2u32
{
	uint32_t			x;
	uint32_t			y;
}						t_2u32;

typedef struct			s_2u64
{
	uint64_t			x;
	uint64_t			y;
}						t_2u64;

typedef struct			s_3f32
{
	float				x;
	float				y;
	float				z;
}						t_3f32;

typedef struct			s_3f64
{
	double				x;
	double				y;
	double				z;
}						t_3f64;

typedef struct			s_3i8
{
	int8_t				x;
	int8_t				y;
	int8_t				z;
}						t_3i8;

typedef struct			s_3i16
{
	int16_t				x;
	int16_t				y;
	int16_t				z;
}						t_3i16;

typedef struct			s_3i32
{
	int32_t				x;
	int32_t				y;
	int32_t				z;
}						t_3i32;

typedef struct			s_3i64
{
	int64_t				x;
	int64_t				y;
	int64_t				z;
}						t_3i64;

typedef struct			s_3u8
{
	uint8_t				x;
	uint8_t				y;
	uint8_t				z;
}						t_3u8;

typedef struct			s_3u16
{
	uint16_t			x;
	uint16_t			y;
	uint16_t			z;
}						t_3u16;

typedef struct			s_3u32
{
	uint32_t			x;
	uint32_t			y;
	uint32_t			z;
}						t_3u32;

typedef struct			s_3u64
{
	uint64_t			x;
	uint64_t			y;
	uint64_t			z;
}						t_3u64;

typedef unsigned char	t_byte;

#endif
