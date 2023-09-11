/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:14:17 by romartin          #+#    #+#             */
/*   Updated: 2023/09/11 21:07:40 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	print_env(t_env *env, char **tmp)
{
	char	*s1;
	char	*str;
	int		i;

	i = 0;
	while (env)
	{
		s1 = mini_strjoin(env->var, "=");
		str = mini_strjoin(s1, env->val);
		tmp[i++] = str;
		free(s1);
		env = env->next;
	}
}

void	jesaispas2(t_minijoker *mini, t_env *first, t_env *env, int i)
{
	char	**tmp;
	char	*s1;
	char	*str;

	if (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
		mini->tokens = mini->tokens->next;
	first = env;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env)
	{	
		if (env->var && env->val)
		{
			s1 = mini_strjoin(env->var, "=");
			str = mini_strjoin(s1, env->val);
			tmp[i++] = str;
			free(s1);
		}
		env = env->next;
	}
	tmp[i] = NULL;
	mini_freetab(mini->env_copy);
	mini->env_copy = tmp;
	mini_ft_lst_clear(first);
}

int	jesaispas(t_minijoker *mini, t_env *first, t_env *env, int i)
{
	char	**tmp;

	if ((mini->tokens->content[0] >= '0' && mini->tokens->content[0] <= '9')
		|| mini->tokens->content[0] == '='
		|| mini_charfind(mini->tokens->content, '=')
		> mini_charfind(mini->tokens->content, '?'))
	{
		mini_putstr_fd(2, "export: `");
		mini_putstr_fd(2, mini->tokens->content);
		mini_putstr_fd(2, "' : not a valid identifier");
		mini_putstr_fd(2, "\n");
		mini->error = 1;
		tmp = (char **)malloc(sizeof(char *) * (i + 1));
		print_env(env, tmp);
		tmp[i] = NULL;
		mini_freetab(mini->env_copy);
		mini->env_copy = tmp;
		mini_ft_lst_clear(first);
		return (1);
	}
	return (0);
}
