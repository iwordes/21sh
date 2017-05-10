/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segdjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 19:36:01 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 19:54:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_asprintf_segdjoin(char *text, char *conv, ssize_t tl, ssize_t cl)
{
	char	*string;

	string = ft_asprintf_segjoin(text, conv, tl, cl);
	free(text);
	free(conv);
	return (string);
}
