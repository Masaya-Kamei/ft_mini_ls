/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:07:22 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/15 18:26:47 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_UTILS_H
# define FT_MINI_LS_UTILS_H

# include "ft_mini_ls.h"

t_list		*merge_sort_lst(t_list *lst, const t_order_func f);
void		free_file_struct(t_file *file);
t_status	release_handling(t_free_func f, void *p, t_status status);
t_status	release_lst_handling(t_free_func f, void *p, t_status status);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);

#endif
