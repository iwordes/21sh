/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:38:37 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 10:34:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	ft_asprintf_parse_flags(const char **fmt, t_printer *printer)
{
	if (**fmt == '+')
		printer->sign = TRUE;
	if (**fmt == ' ')
		printer->pad = TRUE;
	if (**fmt == '-')
		printer->left_just = TRUE;
	if (**fmt == '0')
		printer->zero_pad = TRUE;
	if (**fmt == '\'')
		printer->group = TRUE;
	if (**fmt == '#')
		printer->alt = TRUE;
	if (**fmt == '+' || **fmt == ' ' || **fmt == '-' || **fmt == '0'
		|| **fmt == '\'' || **fmt == '#')
	{
		*fmt += 1;
		return (TRUE);
	}
	else
		return (FALSE);
}
