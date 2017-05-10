/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:18:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/15 13:51:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Return the plain-text portion of the given format string.
**
** 1. Determine the index of the next '%' character. (or '\0')
**    The above index is (also) the length of our substring.
** 2. Create a substring of the above length from the format string.
** 3. Null guard the new substring.
** 4. Increment the format string pointer by the substring length.
** 5. Return the length of the new substring.
*/

static ssize_t	get_text_segment(char **string, const char **fmt)
{
	ssize_t		length;

	length = ft_struntil(*fmt, '%');
	*string = ft_strsub(*fmt, 0, length);
	if (*string == NULL)
		return (-1);
	*fmt += length;
	return (length);
}

/*
** Return the output of the next conversion specifier in the format string.
**
** 1. Determine if there is a conversion spec available.
**    If not, terminate early with an empty string.
** 2. Zero out and initialize a t_printer struct.
** 3. Create a copy of our arguments head. This must be done before parsing to
**    account for calls to va_arg made when parsing '*' for width or precision.
** 4. Parse the conversion spec, storing its data in the t_printer.
** 5. If any '*' were encountered during parsing, add the number encountered
**    to our argument index so we don't reuse those arguments.
** 6. If there literally was no conversion (EOL was hit), return error.
** 7. Get the proper argument.
**    NOTE: This works because the number of encountered
**    stars during parsing is applied incrementally after the current argument
**    index has already been set.
**    NOTE: As defined in `man 3 printf`, mixing '*' and 'N$' in the same
**    selector will result in undefined behavior - you will not get the results
**    you expect, because they apply themselves at different times.
** 8. Dispatch to the proper conversion function, storing the final, formatted
**    length.
** 9. End the temporary va_list and return the final length.
*/

static ssize_t	get_conv_segment(char **string, const char **fmt,
								va_list args, size_t *a)
{
	t_printer	printer;
	ssize_t		length;
	va_list		arg;

	if (**fmt != '%')
	{
		*string = ft_strnew(0);
		return (0);
	}
	ft_bzero(&printer, sizeof(t_printer));
	printer.arg = *a;
	printer.prec = -1;
	va_copy(arg, args);
	while (printer.arg-- != 0)
		va_arg(arg, int);
	ft_asprintf_parse(fmt, arg, &printer);
	if (printer.conv == 0)
	{
		*string = ft_strnew(0);
		return (0);
	}
	*a += printer.stars;
	length = ft_asprintf_dispatch(string, arg, a, &printer);
	va_end(arg);
	return (length);
}

/*
** Given a char**, a format string, and a variadic list of arguments, allocate
** enough space for the formatted string and write it to the first argument.
*/

int				ft_vasprintf(char **string, const char *fmt, va_list args)
{
	char		*seg[2];
	ssize_t		l[3];
	size_t		a;

	a = 0;
	l[2] = 0;
	*string = NULL;
	while (*fmt != 0)
	{
		PF_FAILIF((l[0] = get_text_segment(seg + 0, &fmt)) < 0);
		if ((l[1] = get_conv_segment(seg + 1, &fmt, args, &a)) < 0)
			free(seg[0]);
		PF_FAILIF(l[1] < 0);
		if ((seg[0] = ft_asprintf_segdjoin(seg[0], seg[1], l[0], l[1])) == NULL)
			return ((l[2] == 0) ? ~0L : -l[2]);
		seg[1] = ft_asprintf_segjoin(*string, seg[0], l[2], l[0] + l[1]);
		free(seg[0]);
		PF_FAILIF(seg[1] == NULL);
		free(*string);
		*string = seg[1];
		l[2] += l[0] + l[1];
	}
	return (l[2]);
}
