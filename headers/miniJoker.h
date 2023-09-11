/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniJoker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:22:54 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/11 20:27:52 by romartin         ###   ########.fr       */
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
# include <fcntl.h>

# ifndef PROMPT
#  define PROMPT "\x1b[2K\x1b[0G\x1b[38;2;100;100;100mmini\x1b[31mJoker\x1b[0m> "
# endif

typedef struct s_minijoker {
	char			**env_copy;
	char			*sep[6];
	struct s_token	*tokens;
	struct s_token	*first;
	int				fdin;
	int				fdout;
	int				save_stdout;
	int				save_stdin;
	int				redir_fd;
	int				error;
	int				lerror;
	int				end;
	int				here_doc;
}	t_minijoker;

/* BUILTIN */
int		mini_env(t_minijoker *mini, int i, t_env *env);
int		mini_echo(t_minijoker *mini);
int		mini_pwd(void);
void	mini_cd(t_minijoker *mini);
void	mini_export(t_minijoker *mini);
int		jesaispas(t_minijoker *mini, t_env *first, t_env *env, int i);
void	jesaispas2(t_minijoker *mini, t_env *first, t_env *env, int i);
void	mini_unset(t_minijoker *mini);

/* Parsing */
void	parser(t_minijoker *mini, char *input);
int		mini_len(char *str, char **charset, int i);
int		mini_len2(char *str);
int		mini_len3(t_minijoker *mini, char *str);
char	*mini_cut_to2(char *str, char *charset);
void	parse_env(t_minijoker *mini);
char	str_is_encapsuled(char *str);
char	*get_env_bis(t_minijoker *mini, char *str);
int		mini_pipe(t_minijoker *mini);

void	listen(t_minijoker *mini);
void	sigint(int code);
void	exit_minijoker(t_minijoker *mini, char *str);
char	*get_env(t_minijoker *mini, char *str);
int		true_exec(t_minijoker *mini);
void	mini_exec(t_minijoker *mini);
char	*freetab(char **tab);
int		exec_loop(t_minijoker *mini);
int		remove_encapsuled(t_minijoker *mini);
void	redirection(t_minijoker *mini);

#endif