/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:19:04 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/14 17:42:23 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "ft_mini_ls_utils.h"

void	free_file_struct(t_file *file)
{
	free(file->name);
	free(file);
}

t_status	release_handling(t_free_func f, void *p, t_status status)
{
	f(p);
	return (status);
}

t_status	release_lst_handling(t_free_func f, void *p, t_status status)
{
	ft_lstclear(p, f);
	return (status);
}
