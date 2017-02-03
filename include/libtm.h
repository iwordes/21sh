/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:47:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 14:31:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTM_H
# define LIBTM_H

# include <curses.h>
# include <term.h>
# include <termios.h>

# define TM_UP "\e[A"
# define TM_DOWN "\e[B"
# define TM_RIGHT "\e[C"
# define TM_LEFT "\e[D"

# define TM_BKSP "\e[D \e[D"

# define TM_HOME "\e[H"
# define TM_END "\e[F"

# define TM_CLR_LN ""
# define TM_CLR_SCR ""
# define TM_CLR_EOL "\e[K"
# define TM_CLR_EOS "\e[J"

# define TM_CUR_SAVE "\e7"
# define TM_CUR_REST "\e8"

# define TM_RESET "\e[0m"
# define TM_BOLD "\e[1m"
# define TM_DIM "\e[2m"
# define TM_ITAL "\e[3m"
# define TM_UND "\e[4m"
# define TM_BLINK "\e[5m"
# define TM_REV "\e[7m"
# define TM_INVIS "\e[8m"

# define TM_BLK "\e[30m"
# define TM_RED "\e[31m"
# define TM_GRN "\e[32m"
# define TM_YLW "\e[33m"
# define TM_BLU "\e[34m"
# define TM_MAG "\e[35m"
# define TM_CYN "\e[36m"

# define TM_GRY "\e[90m"

void		tm_putchar(int c);
void		tm_putstr(const char *str);

void		tm_up(void);
void		tm_down(void);
void		tm_right(void);
void		tm_left(void);

void		tm_bksp(void);

void		tm_clr_eol(void);
void		tm_clr_eos(void);

void		tm_cur_save(void);
void		tm_cur_rest(void);

/*
** void		tm_goto(int x, int y);
*/

/*
** void		tm_cls(void);
*/

/*
** void		tm_scr_save(void);
** void		tm_scr_rest(void);
*/

#endif
