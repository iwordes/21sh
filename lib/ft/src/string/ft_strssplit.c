/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strssplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:36 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:27:03 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Splits a string by a given string delimiter and returns an array of
** substrings.
*/

static int	get_substring_cnt(const char *string, const char *delim)
{
	size_t	cnt;
	size_t	delim_length;

	if (*delim == 0)
		return (1);
	cnt = 0;
	delim_length = ft_strlen(delim);
	while (*string != 0)
	{
		if (ft_strnequ(string, delim, delim_length))
		{
			string += delim_length;
			while (ft_strnequ(string, delim, delim_length))
				string += delim_length;
			cnt++;
		}
		else
			string++;
	}
	return (cnt);
}

static char	**panic(char **substrings)
{
	while (*substrings)
	{
		free(*substrings);
		substrings++;
	}
	return (NULL);
}

static void	ft_strssplit_init(const char *dm, size_t *i, size_t *s, size_t *dl)
{
	*i = 0;
	*s = 0;
	*dl = ft_strlen(dm);
}

char		**ft_strssplit(const char *string, const char *delim)
{
	char	**substr;
	size_t	substring_cnt;
	size_t	dl;
	size_t	i;
	size_t	s;

	if (string == NULL || delim == NULL)
		return (NULL);
	ft_strssplit_init(string, &i, &s, &dl);
	substring_cnt = get_substring_cnt(string, delim);
	NULL_GUARD(substr = malloc(sizeof(char*) * (substring_cnt + 1)));
	while (s < substring_cnt)
	{
		while (string[i] != 0 && ft_strnequ(string + i, delim, dl))
			i += dl;
		if (string[i] != 0 && (substr[s] = ft_strsub(string, i++,
			ft_struntils(string, delim))) != NULL)
			return (panic(substr));
		while (string[i] != 0 && !ft_strnequ(string + i, delim, dl))
			i++;
		s++;
	}
	substr[s] = NULL;
	return (substr);
}
