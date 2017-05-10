/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrjoin_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:13:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/03 20:13:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Performance considerations:
** - ft_strnew zeroes out all available memory. While it may complicate the
**   internal copying logic, it may be wise to forego it in favor of malloc.
*/

char	*ft_vstrjoin_(const char *current, va_list args)
{
	va_list		largs;
	char		*str;

	NULL_GUARD(current);
	largs = va_copy(args);
	str = ft_strnew(ft_vstrlen_(current, largs) + 1);
	va_end(largs);
	NULL_GUARD(str);
	ft_strcat(str, current);
	while ((current = va_arg(args, char*)) != NULL)
		ft_strcat(str, current);
	return (str);
}
