/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:50:26 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/08 16:39:02 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_cd(t_minijoker *mini)
{
	char	*path;
	char	*str;
	int		error;

	error = SUCCESS;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens->content
		|| mini_strcmp(mini->tokens->content, "~", 0) == 0)
		chdir(get_env(mini, "HOME"));
	else if (chdir(mini->tokens->content) == -1)
	{
		path = getcwd(NULL, 0);
		str = mini_strjoin(path, "/");
		path = mini_strjoin(str, mini->tokens->content);
		free(str);
		if (access(path, X_OK) == 0)
			error = EXEC_FILE;
		else
			error = DIR_NOT_FOUND;
		free(path);
	}
	return (error);
}
