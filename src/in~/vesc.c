/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vesc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:50:47 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/11 13:53:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** V-escape the next keypress (interpreted literally)
** If the next keypress contains invisible sequences, they are print-escaped and
** can be moved across without maligning the cursor.
** Ctrl+V
*/
