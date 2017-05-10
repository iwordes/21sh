/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_invis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:30:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 13:00:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t		invis_len(const char *str)
{
	size_t	l;

	l = 0;
	while (*str != 0)
	{
		if (*str < ' ' || *str == 127)
			l += 2;
		else
			l += 1;
		str += 1;
	}
	return (l);
}

static void	invis_cpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (*src != 0)
	{
		if (ft_iscntrl(*src))
		{
			dest[i++] = '^';
			dest[i++] = (*src + 64) & 127;
		}
		else
			dest[i++] = *src;
		src += 1;
	}
	dest[i] = 0;
}

ssize_t		ft_asprintf_conv_invis(char **string, va_list arg, t_printer *p)
{
	char	*raw;
	size_t	l;

	if (p->prec >= 0)
		raw = ft_strndup(va_arg(arg, char*), p->prec);
	else
		raw = ft_strdup(va_arg(arg, char*));
	if (raw == NULL)
		return (-1);
	l = invis_len(raw);
	if ((*string = (char*)malloc(l + 1)) == NULL)
	{
		free(raw);
		return (-1);
	}
	invis_cpy(*string, raw);
	free(raw);
	return (l);
}
