/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:10:37 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/15 18:26:19 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "ft_mini_ls_utils.h"

static void	divide_into_two_lst(
	t_list *lst, t_list **left_lst, t_list **right_lst)
{
	int		count;

	*left_lst = lst;
	count = ft_lstsize(lst) / 2;
	while (--count > 0)
		lst = lst->next;
	*right_lst = lst->next;
	lst->next = NULL;
}

static t_list	*merge_two_lst(
	t_list *left_lst, t_list *right_lst, const t_order_func f)
{
	t_list	dummy_lst;
	t_list	*sorted_lst;

	dummy_lst.next = NULL;
	sorted_lst = &dummy_lst;
	while (left_lst && right_lst)
	{
		if (f(left_lst->content, right_lst->content))
		{
			sorted_lst->next = left_lst;
			left_lst = left_lst->next;
		}
		else
		{
			sorted_lst->next = right_lst;
			right_lst = right_lst->next;
		}
		sorted_lst = sorted_lst->next;
	}
	if (left_lst == NULL)
		sorted_lst->next = right_lst;
	else
		sorted_lst->next = left_lst;
	return (dummy_lst.next);
}

t_list	*merge_sort_lst(t_list *lst, const t_order_func f)
{
	t_list	*left_lst;
	t_list	*right_lst;

	if (lst == NULL || lst->next == NULL)
		return (lst);
	divide_into_two_lst(lst, &left_lst, &right_lst);
	left_lst = merge_sort_lst(left_lst, f);
	right_lst = merge_sort_lst(right_lst, f);
	return (merge_two_lst(left_lst, right_lst, f));
}
