/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treefind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:53:13 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:17:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Find some data in a tree.
*/

t_tree		*ft_treefind(t_tree *tree, void *data, int (*cmp)(void*, void*))
{
	int		outcome;

	if (tree != NULL)
	{
		while ((outcome = cmp(tree->data, data)) != 0)
		{
			if (outcome < 0 && tree->left != NULL)
				tree = tree->left;
			else if (outcome > 0 && tree->right != NULL)
				tree = tree->right;
			else
				return (NULL);
		}
		return (tree);
	}
	return (NULL);
}
