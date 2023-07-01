#include <stdio.h>
#include <stdlib.h>
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
        if (str[cpt] == ' ')
            break;
        n = 0;
        while (charset[n])
        {
            j = 0;
            while (charset[n][j] && str[cpt + j])
            {
                if (charset[n][j] != str[cpt + j])
                    break;
                j++;
            }
            if (charset[n][j] == '\0')
                break;
            n++;
        }
        if (charset[n] && charset[n][j] == '\0')
            break;
        cpt++;
    }
    if (cpt - (*i) == 0 && charset[n])
    {
        j = 0;
        while (charset[n][j++])
            cpt++;
    }
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
    size = 1;
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        if (str[i] == ' ')
            size++;
        n = 0;
        while (charset[n])
        {
            j = 0;
            while (str[i + j] && charset[n][j])
            {
                if (str[i + j] != charset[n][j])
                    break;
                j++;
            }
            if (charset[n][j] == '\0')
            {
                size++;
                break ;
            }
            n++;
        }
        i++;
    }
    res = (char **)malloc(sizeof(char *) * (size + 1));
    if (!res)
        return (NULL);
    j = 0;
    i = 0;
    while (str[i] == ' ')
        i++;
    while (j < size)
    {
        res[j] = ft_ministrdup(str, charset, &i);
        j++;
    }
    res[j] = NULL;
    return (res);
}
int main() {
    char *specialChars[6] = {
        "<", ">", "|", "<<", ">>"
    };
    specialChars[5] = NULL;
    char **tab = minisplit("oui je| suis la", specialChars);
    for(int i = 0; tab[i]; i++)
        printf("%s\n", tab[i]);
}