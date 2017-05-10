/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:15:30 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Join a NULL-terminated array of strings into a single string.
*/

char		*ft_strjoin_arr(const char **array, const char *delimiter)
{
	char	*string;
	char	*tmp;

	NULL_GUARD(array);
	NULL_GUARD(*array);
	NULL_GUARD(delimiter);
	string = ft_strdup(*array);
	while (*(array += 1) != NULL)
	{
		NULL_GUARD(string);
		tmp = ft_strjoin(string, delimiter);
		free(string);
		NULL_GUARD(tmp);
		string = ft_strjoin(tmp, *array);
		free(tmp);
	}
	return (string);
}
