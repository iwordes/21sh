/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:38:50 by iwordes           #+#    #+#             */
/*   Updated: 2016/11/16 16:38:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINTS_H
# define FT_POINTS_H

/*
** TODO: Differentiate properly between the two kinds of coordinates.
*/

typedef struct	s_2d_coord
{
	long		x;
	long		y;
}				t_2d_coord;

typedef struct	s_3d_coord
{
	long		x;
	long		y;
	long		z;
}				t_3d_coord;

typedef struct	s_pt2d
{
	double		x;
	double		y;
	double		rot;
}				t_pt2d;

typedef struct	s_pt3d
{
	double		x;
	double		y;
	double		z;
	double		pitch;
	double		yaw;
	double		roll;
}				t_pt3d;

#endif
