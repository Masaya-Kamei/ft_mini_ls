/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:00:24 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/19 19:51:04 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdbool.h>

# define ARG_ERR_MSG "Not supported arguments"

typedef enum e_status
{
	SUCCESS	= 0,
	ERROR	= 1
}			t_status;

typedef struct s_file
{
	char			*name;
	struct timespec	last_update_time;
}					t_file;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef bool	(*t_order_func)();
typedef void	(*t_free_func)();

// main
t_status	ft_mini_ls(void);

// utils
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
