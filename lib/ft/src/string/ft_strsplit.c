/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:45:02 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	get_chunk_count(const char *string, char delimiter)
{
	size_t		chunk_count;

	if (delimiter == 0)
		return (1);
	else
	{
		chunk_count = 0;
		while (*string != 0)
		{
			while (*string == delimiter)
				string++;
			if (*string != 0)
			{
				while (*string != 0 && *string != delimiter)
					string++;
				chunk_count++;
			}
		}
		return (chunk_count);
	}
}

/*
** When you make a mess, clean up after yourself, or so they say.
*/

static char		**panic(char **substrings)
{
	while (*substrings != NULL)
	{
		free(*substrings);
		substrings++;
	}
	return (NULL);
}

static char		**split_string(const char *string, char delim)
{
	size_t		chunk_count;
	char		**chunks;
	size_t		i;

	i = 0;
	chunk_count = get_chunk_count(string, delim);
	chunks = (char**)malloc(sizeof(char*) * (chunk_count + 1));
	NULL_GUARD(chunks);
	if (chunk_count > 0)
		while (i < chunk_count)
		{
			while (*string == delim)
				string++;
			chunks[i] = ft_strsub(string, 0, ft_struntil(string, delim));
			if (chunks[i] == NULL)
				return (panic(chunks));
			while (*string != 0 && *string != delim)
				string++;
			i++;
		}
	chunks[chunk_count] = NULL;
	return (chunks);
}

char			**ft_strsplit(const char *string, char delimiter)
{
	if (string != NULL)
		return (split_string(string, delimiter));
	else
		return (NULL);
}
