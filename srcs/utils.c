/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:41:34 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/01 17:17:22 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

int	ft_charfind(char *str, char c)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (i - 1);
	return (i);
}

char	*ft_cut_to(char *str, char c)
{
	int		i;
	int		size;
	char	*ret;

	size = ft_charfind(str, c);
	if (size == -1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

int	ft_strcmp(char *s1, char *s2, int ended)
{
	int	i;

	if (!s1)
		return (-1);
	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			break ;
	if (ended && s1[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *s1)
{
	int		cpt;
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	cpt = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (cpt + 1));
	if(!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}

int	ft_lrstrcmp(char *s1, char *s2)
{
	int	i;

	if (!s1)
		return (-1);
	i = -1;
	while (s1[++i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
	}
	if (s1[i] == '=')
		return (0);
	return (s1[i] - s2[i]);
}
