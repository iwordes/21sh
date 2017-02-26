/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 21:30:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 13:03:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Insert shell variables into a string, splitting as necessary, and return
** all substrings when finished.
*/

/*
#define VAL_CHR_(C) (ft_isalnum(C) || C == '_')

static size_t	til_delim(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l] != 0 && (VAL_CHR_(str[l]) || ft_isdigit(str[l])))
		l += 1;
	return (l);
}

#define VAL_1__1(C) (C != '~' && C != '#' && C != '%' && C != ':' && C != '/')
#define VAL_1_(C) (VAL_1__1(C) || ft_isdigit(C))

static char	*get_var(const char *str)
{
	char	*key;
	char	*val;

	if (VAL_CHR_(str[0]))
		MGUARD(key = ft_strsub(str, 0, til_delim(str + 1) + 1));
	else if (str[0] != 0 && VAL_1_(str[0]))
	{
		MGUARD(key = ft_strndup(str, 1));
		val = env_get_safe(key);
	}
	else
		return ("$");
	free(key);
	return (val);
}

char		**subs_var(t_token *tk)
{
	char	**argv;
	char	*var;
	char	*str;
	size_t	l;

	str = tk->val;
	while (*str != 0)
	{
		l = ft_struntil(str, '$');
		if (str[l] == '$')
		{
			envar = get_var(str + l + 1);
			if ((segs = ws_segs(envar)) > 0)

			l += til_delim(str + l);
		}

	}
	return (argv);
}
*/

/*
** [stubbed]
*/

char	**subs_var(t_token *tk)
{
	char	**argv;

	MGUARD(argv = ZALT(char*, 2));
	MGUARD(argv[0] = ft_strdup(tk->val));
	return (argv);
}
