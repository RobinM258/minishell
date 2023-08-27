/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:23:29 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/25 22:08:19 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

# include <stdlib.h>
# include <unistd.h>

enum e_plop	{PARAM,
	OTHER};
	enum e_errors {SUCCESS,
	ARG_NUMBER,
	END,
	MALLOC_ERROR,
	EXEC_FILE,
	DIR_NOT_FOUND,
	INPUT_ERROR,
	QUOTE_ERROR,
	UNKNOW_COMMAND,
	UNKNOW_ERROR,
	FILE_NOT_FOUND,
	OPEN_ERROR,
	FORK_ERROR};
	typedef struct s_token {
		char *content;
	int altego;
	struct s_token * next;
	struct s_token * prev;
} t_token;

t_token	*mini_split(char *str, char **charset, int *error);
char	**mini_ft_split(char *str, char c);
int		mini_tablen(char **tab);
int		mini_strlen(char *str);
char	*mini_strjoin(char *s1, char *s2);
char	*mini_strdup(char *s1);
int		mini_strcmp(char *s1, char *s2, int ended);
int		mini_lrstrcmp(char *s1, char *s2);
int		mini_is_intab(char **tab, char *str, int p);
char	*mini_cut_to(char *str, char c);
int		mini_charfind(char *str, char c);
void	mini_freetab(char **tab);
int		mini_strcpy(char *src, char *dst);
void	mini_putstr_fd(int fd, char *str);
char	*mini_append_path(char *s1, char *s2);
int		mini_is_valid_func(char *path, char *str);
int		is_mini_func(char *str);
char	*mini_itoa(int n);
void	*mini_calloc(size_t count, size_t size);
void	mini_bzero(void *s, size_t n);
char	*mini_tolower(char *str);
void	mini_tokendelone(t_token **tokens);
int		mini_tokenfind(t_token *tokens,
			char c, int p);

/* tokens */
void	mini_tokenclear(t_token *lst);
t_token	*mini_tokenlast(t_token *lst);
int		mini_tokenadd_back(t_token **lst, t_token *token);
t_token	*mini_tokennew(char *str, int plop);
void	mini_tokenwrite(t_token *lst);
t_token	*mini_tokenfirst(t_token *lst);

typedef struct s_env
{
	char *var;
	char *val;
	struct s_env * next;
} t_env ;
#endif