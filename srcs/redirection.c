/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:35:37 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 17:10:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int open_redirection(t_minijoker *mini)
{
    int     fd;
    int     flag;

    if (mini_strcmp(mini->tokens->prev->content, "<", 0) == 0)
        flag = O_RDONLY;
    if (mini_strcmp(mini->tokens->prev->content, ">", 0) == 0)
        flag = O_WRONLY | O_CREAT | O_TRUNC;
    if (mini_strcmp(mini->tokens->prev->content, ">>", 0) == 0)
        flag = O_WRONLY | O_CREAT | O_APPEND;
    fd = open(mini->tokens->content, flag, 0777);
    if (fd == -1)
        return (OPEN_ERROR);
    if (mini_strcmp(mini->tokens->prev->content, "<", 0) == 0)
        mini->fdout = dup2(fd, 0);
    else
        mini->fdin = dup2(fd, 1);
    return (SUCCESS);
}

int redirection(t_minijoker *mini)
{
    pid_t   pid;
    int     statut;
    int     error;

    error = SUCCESS;
    pid = fork();
    if (pid == -1)
        return (FORK_ERROR);
    if (pid == 0)
    {
        while (mini->tokens->next)
        {
            if (mini_is_intab(mini->sep, mini->tokens->content))
            {
                mini->tokens = mini->tokens->next;
                if (!mini->tokens)
                {
                    error = FILE_NOT_FOUND;
                    break ;
                }
                error = open_redirection(mini);
                if (error != SUCCESS)
                    break ;
            }
            else
                mini->tokens = mini->tokens->next;
        }
        if (!error)
        {
            mini->tokens = mini_tokenfirst(mini->tokens);
            error = exec_loop(mini);
        }
        exit(error);
    }
    wait(&statut);
    return (WEXITSTATUS(statut));
}
