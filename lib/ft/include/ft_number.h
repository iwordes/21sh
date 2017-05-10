/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:38:49 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/27 13:04:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBER_H
# define FT_NUMBER_H

# include <stdint.h>

uintmax_t	ft_absolute(intmax_t integer);

intmax_t	ft_greater(intmax_t input1, intmax_t input2);
intmax_t	ft_lesser(intmax_t input1, intmax_t input2);

int			ft_intlen(intmax_t integer);
int			ft_intlen_base(intmax_t integer, char base);
int			ft_uintlen(uintmax_t integer);
int			ft_uintlen_base(uintmax_t integer, char base);

intmax_t	ft_square(intmax_t integer);
intmax_t	ft_power(intmax_t integer, unsigned exponent);

#endif
