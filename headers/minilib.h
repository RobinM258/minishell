/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:23:29 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/11 20:17:43 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_env
{
	char			*var;
	char			*val;
	struct s_env	*next;
}	t_env;

enum e_plop	{PARAM,
	NO_SPACE,
	OTHER};
	enum e_errors {HERE_DOC,
	FAILURE,
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
	FORK_ERROR,
	NUM_ARG};
	typedef struct s_token {
		char *content;
	int altego;
	struct s_token * next;
	struct s_token * prev;
} t_token;

void	mini_stradd(char *s1, char *toadd);
t_token	*mini_split(char *str, char **charset, int *error);
int		mini_len(char *str, char **charset, int i);
char	*ministrdup(char *str, char **charset, int	*i);
t_token	*quit(t_token *tokens);
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
char	**mini_freetab(char **tab);
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
int		mini_tokenfindchar(t_token *tokens,
			char c, int plop);
int		mini_tokenfindstr(t_token *tokens, char *str);
int		mini_alpha(char c);
int		mini_alphanum(char c);
int		mini_atoi(const char *str);
int		mini_has_alpha(char *str);

void	mini_ft_lst_add_back(t_env **lst, char *var, char *val);
t_env	*mini_ft_lst_last(t_env *env);
t_env	*mini_ft_lst_new(char *var, char *val);
void	mini_ft_lst_clear(t_env *env);
/* tokens */
void	mini_tokenclear(t_token *lst);
t_token	*mini_tokenlast(t_token *lst);
int		mini_tokenadd_back(t_token **lst, t_token *token);
t_token	*mini_tokennew(char *str, int plop);
void	mini_tokenwrite(t_token *lst);
t_token	*mini_tokenfirst(t_token *lst);

#endif