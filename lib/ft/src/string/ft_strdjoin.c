/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:15:31 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** ft_strdjoin(char *left, char *right)
** ===========
** From two input strings, creates a third string and returns it. Additionally,
** it frees both of the inputs.
*/

char	*ft_strdjoin(char *left, char *right)
{
	char	*string;

	string = ft_strjoin(left, right);
	free(left);
	free(right);
	return (string);
}
