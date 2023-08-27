/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_is_valid_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:40:29 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:30:25 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	is_mini_func(char *str)
{
	if (mini_strcmp(str, "echo", 0) == 0)
		return (1);
	if (mini_strcmp(str, "cd", 0) == 0)
		return (1);
	if (mini_strcmp(str, "pwd", 0) == 0)
		return (1);
	if (mini_strcmp(str, "env", 0) == 0)
		return (1);
	if (mini_strcmp(str, "export", 0) == 0)
		return (1);
	if (mini_strcmp(str, "unset", 0) == 0)
		return (1);
	return (0);
}

static int	is_true_func(char *path, char *str)
{
	char	*exec;
	int		ret;

	ret = 0;
	exec = mini_append_path(path, str);
	if (access(exec, X_OK) == 0)
		ret = 1;
	free(exec);
	return (ret);
}

int	mini_is_valid_func(char *path, char *str)
{
	return (is_mini_func(str) || is_true_func(path, str));
}
