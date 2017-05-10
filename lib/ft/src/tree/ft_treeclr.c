/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:53:29 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:17:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Frees the data pointer of all nodes in the tree and sets them to NULL.
*/

void	ft_treeclr(t_tree *tree)
{
	if (tree->left != NULL)
		ft_treeclr(tree->left);
	if (tree->right != NULL)
		ft_treeclr(tree->right);
	free(tree->data);
	tree->data = NULL;
}
