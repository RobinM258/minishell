/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:23:29 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 10:44:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

# include <stdlib.h>

typedef struct s_token {
	char			*content;
	struct s_token *next;
	struct s_token *prev;
} t_token;

t_token	*mini_split(char *str, char **charset);
char	**mini_ft_split(char *str, char c);
int		mini_tablen(char **tab);
int		mini_strlen(char *str);
char	*mini_strjoin(char *s1, char *s2);
char	*mini_strdup(char *s1);
int		mini_strcmp(char *s1, char *s2, int ended);
int		mini_lrstrcmp(char *s1, char *s2);
int		mini_is_intab(char **tab, char *str);
char	*mini_cut_to(char *str, char c);
int		mini_charfind(char *str, char c);
void	mini_freetab(char **tab);
int		mini_strcpy(char *src, char *dst);

/* tokens */
void    mini_tokenclear(t_token *lst);
t_token *mini_tokenlast(t_token *lst);
int    mini_tokenadd_back(t_token **lst, t_token *token);
t_token *mini_tokennew(t_token *lst, char *str);
void    mini_tokenwrite(t_token *lst);
t_token *mini_tokenfirst(t_token *lst);

#endif