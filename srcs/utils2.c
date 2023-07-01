/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:47:29 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/01 15:35:00 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void    freetab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}

char    *ft_ministrdup(char *str, char **charset, int *i)
{
    int cpt;
    char    *res;
    int j;
    int n;

    if (!str || !str[*i])
        return (NULL);
    cpt = *i;
    while (str[cpt])
    {
        n = 0;
        while (charset[n])
        {
            if (ft_strcmp(charset[n], &str[cpt], 1) == 0)
                break ;
            n++;
        }
        if (charset[n])
            break;
        cpt++;
    }
    if (cpt - (*i) == 0 && charset[n])
        cpt = ft_strlen(charset[n]);
    res = (char *)malloc(sizeof(char) * (cpt - *i + 1));
    if (!res)
        return (NULL);
    j = 0;
    while (cpt - *i > 0)
    {
        res[j] = str[*i];
        j++;
        (*i)++;
    }
    res[j] = '\0';
    if (str[*i] == ' ')
        (*i)++;
    return (res);
}

char    **minisplit(char *str, char **charset)
{
    int size;
    int i;
    int n;
    int j;
    char    **res;

    i = 0;
    size = 0;
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        n = 0;
        while (charset[n])
        {
            if (ft_strcmp(charset[n], &str[i], 1) == 0)
            {
                if (str[i + ft_strlen(charset[n])] != '\0')
                    size++;
                while (str[i] && !ft_strcmp(charset[n], &str[i], 1))
                    i += ft_strlen(charset[n]);
                break ;
            }
            n++;
        }
        if (!charset[n])
            i++;
    }
    if (size != 0 || (size == 0 && str[0] != '\0'))
        size++;
    res = (char **)malloc(sizeof(char *) * (size + 1));
    if (!res)
        return (NULL);
    j = 0;
    i = 0;
    while (j < size)
    {
        while (str[i] == ' ')
            i++;
        if (!str[i])
            break ;
        res[j] = ft_ministrdup(str, charset, &i);
        if (!res[j])
        {
            freetab(res);
            return (NULL);
        }
        j++;
    }
    res[j] = NULL;
    return (res);
}

int is_intab(char **tab, char *str)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (ft_strcmp(tab[i], str, 1) == 0)
            return (1);
        i++;
    }
    return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	int		i;
	int		j;
	char	*red;

	j = -1;
	i = -1;
	if (!s1 || !s2)
		return (0);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	red = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!red)
		return (NULL);
	while (s1[++i])
		red[i] = s1[i];
	while (s2[++j])
	{
		red[i] = s2[j];
		i++;
	}
	red[i] = '\0';
	return (red);
}
