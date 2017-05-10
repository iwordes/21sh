/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:30 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:26:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** ft_strrep(const char*, const char*, const char*)
** =========
** Given three strings, replaces each instance of the second in the first with
** the third, returning a newly allocated string containing those modifications.
** = If *find is an empty string, returns a copy of *string.
**
** Example 1:
** Input #1: "A string of characters."
** Input #2: "characters"
** Input #3: "words"
** Output: "A string of words."
**
** Example 2:
** Input 1: "The rise and fall\nof Bob the Baker"
** Input 2: "\n"
** Input 3: " "
** Output: "The rise and fall of Bob the Baker"
**
** Room for optimizations:
** - ft_strlen is run twice on both find and replace, once in each function.
**   However, ft_strrep is already 25 lines long.
*/

static size_t	get_final_size(const char *string, const char *find,
													const char *replace)
{
	size_t		l;
	size_t		fl;
	size_t		rl;

	l = 0;
	fl = ft_strlen(find);
	rl = ft_strlen(replace);
	while (*string != 0)
	{
		if (ft_strncmp(string, find, fl) == 0)
		{
			string += fl - 1;
			l += rl - 1;
		}
		string++;
		l++;
	}
	return (l);
}

char			*ft_strrep(const char *string, const char *find,
												const char *replace)
{
	char		*newstring;
	size_t		i;
	size_t		fl;
	size_t		rl;

	if (string == NULL || find == NULL || replace == NULL)
		return (NULL);
	i = 0;
	fl = ft_strlen(find);
	rl = ft_strlen(replace);
	NULL_GUARD(newstring = ft_strnew(get_final_size(string, find, replace)));
	while (*string)
	{
		if (ft_strncmp(string, find, fl) == 0 && *find != 0)
		{
			ft_strcpy(newstring + i, replace);
			string += fl - 1;
			i += rl - 1;
		}
		else
			newstring[i] = *string;
		string++;
		i++;
	}
	return (newstring);
}
