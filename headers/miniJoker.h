#ifndef MINIJOKER
# define MINIJOKER

    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <unistd.h>
    #include <readline/readline.h>
    #include <readline/history.h>
    #include <sys/time.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <termios.h>

    # ifndef EXIT_SUCESS
    #  define EXIT_SUCCESS 0
    # endif
    # ifndef EXIT_FAILLURE
    #  define EXIT_FAILLURE 1
    # endif
	#ifndef PROMPT
	# define PROMPT "\n"
	#endif

    typedef struct  s_miniJoker {
        char    **env_copy;
        char    *sep[7];
        char    **tokens;
    } t_miniJoker;

    void    listen(t_miniJoker *mini);
    int     parser(t_miniJoker *mini, char *input);
	char	*ft_cut_to(char *str, char c);
	int	    ft_charfind(char *str, char c);
	size_t	ft_strlen(char *str);
	int	    ft_strcmp(char *s1, char *s2, int ended);
    void	sigint(int code);
    char	*ft_strdup(char *s1);
    void    exit_miniJoker(t_miniJoker *mini, char *str);
    char    *getEnv(t_miniJoker *mini, char *str);
    int	    ft_lrstrcmp(char *s1, char *s2);
    char    **minisplit(char *str, char **charset);
    int     true_exec(t_miniJoker *mini, int i);
    int 	exec_ft(t_miniJoker *mini);
    void    freetab(char **tab);
    int     ft_echo(t_miniJoker *mini);
    int     ft_pwd(void);
    int     ft_cd(t_miniJoker *mini);
    char	*ft_strjoin(char *s1, char *s2);
    int     is_intab(char **tab, char *str);
    void    exec_loop(char *str, t_miniJoker *mini);
    int     ft_env(t_miniJoker *mini);
    int     is_ft_func(t_miniJoker *mini, int i);
    int     ft_export(t_miniJoker *mini, int index);
    char	**ft_split(char *str, char c);
    int     ft_unset(t_miniJoker *mini, int index);

#endif