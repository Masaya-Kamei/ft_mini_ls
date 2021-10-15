/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:00:24 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/15 15:32:39 by mkamei           ###   ########.fr       */
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

t_status	ft_mini_ls(void);

#endif
