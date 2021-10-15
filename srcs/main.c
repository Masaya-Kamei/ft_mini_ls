/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:01:08 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/14 17:59:30 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "ft_mini_ls_utils.h"

int	main(int argc, char **argv)
{
	(void)(**argv);
	if (argc != 1)
	{
		write(STDERR_FILENO, ARG_ERR_MSG, ft_strlen(ARG_ERR_MSG));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	if (ft_mini_ls() == ERROR)
	{
		perror(NULL);
		return (1);
	}
	return (0);
}
