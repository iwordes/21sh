/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:03 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:18:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_tree	*ft_treenew(void *data)
{
	t_tree	*tree;

	if ((tree = (t_tree*)malloc(sizeof(t_tree))) != NULL)
	{
		tree->data = data;
		tree->left = NULL;
		tree->right = NULL;
	}
	return (tree);
}
