/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:10 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:17:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_treeins(t_tree *tree, void *data, int (*cmp)(void*, void*))
{
	int		outcome;
	t_tree	*next;

	if (tree != NULL && cmp != NULL)
		while (tree->left != NULL || tree->right != NULL)
		{
			if ((outcome = cmp(data, tree->data)) <= 0)
				next = tree->left;
			else
				next = tree->right;
			if (next != NULL)
				tree = next;
			else
			{
				if (outcome <= 0)
					tree->right = ft_treenew(data);
				else
					tree->left = ft_treenew(data);
				return ;
			}
		}
}
