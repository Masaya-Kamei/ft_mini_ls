/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:42:58 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/19 19:51:28 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static t_status	create_new_file_lst(const char *file_name
	, const struct timespec last_update_time, t_list **new_lst)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (file == NULL)
		return (ERROR);
	file->name = ft_strdup(file_name);
	if (file->name == NULL)
		return (release_handling(free, file, ERROR));
	file->last_update_time = last_update_time;
	*new_lst = ft_lstnew(file);
	if (*new_lst == NULL)
		return (release_handling(free_file_struct, file, ERROR));
	return (SUCCESS);
}

static t_status	read_current_dir_files(t_list **file_lst)
{
	DIR				*dir;
	struct dirent	*dp;
	struct stat		sb;
	t_list			*new_lst;

	dir = opendir(".");
	if (dir == NULL)
		return (ERROR);
	*file_lst = NULL;
	while (1)
	{
		dp = readdir(dir);
		if (dp == NULL)
			break ;
		else if (dp->d_name[0] == '.')
			continue ;
		if (lstat(dp->d_name, &sb) == -1)
			return (release_lst_handling(free_file_struct, &file_lst, ERROR));
		if (create_new_file_lst(dp->d_name, sb.st_mtimespec, &new_lst) == ERROR)
			return (release_lst_handling(free_file_struct, &file_lst, ERROR));
		ft_lstadd_front(file_lst, new_lst);
	}
	if (closedir(dir) == -1)
		return (release_lst_handling(free_file_struct, &file_lst, ERROR));
	return (SUCCESS);
}

static bool	is_older_update_time(
	const t_file *target_file, const t_file *comp_file)
{
	long	flag;

	flag = target_file->last_update_time.tv_sec
		- comp_file->last_update_time.tv_sec;
	if (flag != 0)
		return (flag < 0);
	flag = target_file->last_update_time.tv_nsec
		- comp_file->last_update_time.tv_nsec;
	if (flag != 0)
		return (flag < 0);
	return (ft_strncmp(target_file->name
			, comp_file->name, ft_strlen(target_file->name) + 1) > 0);
}

static void	write_file_names(t_list *file_lst)
{
	t_list	*lst;
	char	*file_name;

	lst = file_lst;
	while (lst)
	{
		file_name = ((t_file *)lst->content)->name;
		write(STDOUT_FILENO, file_name, ft_strlen(file_name));
		write(STDOUT_FILENO, "\n", 1);
		lst = lst->next;
	}
}

t_status	ft_mini_ls(void)
{
	t_list	*file_lst;

	if (read_current_dir_files(&file_lst) == ERROR)
		return (ERROR);
	file_lst = merge_sort_lst(file_lst, is_older_update_time);
	write_file_names(file_lst);
	return (release_lst_handling(free_file_struct, &file_lst, SUCCESS));
}
