/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniJoker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:22:54 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/08 13:56:07 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIJOKER_H
# define MINIJOKER_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/time.h>
# include <dirent.h>
# include <sys/types.h>
# include "minilib.h"
# include <sys/wait.h>
#include <fcntl.h>

# ifndef PROMPT
#  define PROMPT "\x1b[30mmini\x1b[31mJoker\x1b[0m> "
# endif

enum e_errors	{SUCCESS, 	//0
	ARG_NUMBER, 			//1
	END, 					//2
	MALLOC_ERROR,			//3
	EXEC_FILE,				//4
	DIR_NOT_FOUND,			//5
	INPUT_ERROR,			//6
	QUOTE_ERROR,			//7
	UNKNOW_COMMAND,			//8
	UNKNOW_ERROR,			//9
	FILE_NOT_FOUND,			//10
	OPEN_ERROR,				//11
	FORK_ERROR};			//12
	typedef struct s_minijoker {
	char **env_copy;
	char *sep[6];
	struct s_token	*tokens;
	int fdin;
	int	fdout;
}	t_minijoker;

/* BUILTIN */
int		mini_env(t_minijoker *mini);
int		mini_echo(t_minijoker *mini);
int		mini_pwd(void);
int		mini_cd(t_minijoker *mini);
int		mini_export(t_minijoker *mini);
int		mini_unset(t_minijoker *mini);
int		mini_pwd(void);

/* Parsing */
int		parser(t_minijoker *mini, char *input);
char	str_is_encapsuled(char *str);
int		tab_is_encapsuled(char **tab);
int		encapsuled_strlen(char *str);
int		encap_tablen(char **tab);
char	*simpledup_without_quote(char *str);
int		size_encapsuled(char **tab, int *i, char quote);
char	*copy_until_encapsuled(char **tab, int *i, int *kr, char quote);
char	*multipledup_without_quote(char **tab, int *i, char quote);
int		remove_encapsuled(t_minijoker *mini);
int		flemme_exit(char **tab);

void	listen(t_minijoker *mini);
void	sigint(int code);
void	exit_minijoker(t_minijoker *mini, char *str);
char	*get_env(t_minijoker *mini, char *str);
int		true_exec(t_minijoker *mini);
int		mini_exec(t_minijoker *mini);
void	freetab(char **tab);
int		exec_loop(t_minijoker *mini);
int		is_mini_func(t_minijoker *mini);
int		remove_encapsuled(t_minijoker *mini);
int 	redirection(t_minijoker *mini);

#endif