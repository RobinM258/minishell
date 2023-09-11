NAME = minilib.a

FILES = mini_charfind \
	mini_stradd \
	mini_split \
	mini_cut_to \
	mini_ft_split \
	mini_is_intab \
	mini_lrstrcmp \
	mini_strcmp \
	mini_strdup \
	mini_strjoin \
	mini_strlen \
	mini_tablen \
	mini_freetab \
	mini_strcpy \
	mini_tokenclear \
	mini_tokenlast \
	mini_tokenadd_back \
	mini_tokennew \
	mini_tokenwrite \
	mini_tokenfirst \
	mini_putstr_fd \
	mini_append_path \
	mini_is_valid_func \
	mini_itoa \
	mini_calloc \
	mini_bzero \
	mini_tolower \
	mini_tokendelone \
	mini_tokenfind \
	mini_alpha \
	mini_atoi \
	mini_ft_lst_last \
	mini_ft_lst_new \
	mini_ft_lst_add_back \
	mini_ft_lst_clear

S = $(foreach f, $(FILES), $(f).c)
OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I../headers

all: $(NAME)

$(NAME): $(OBJ)
	@printf ">  \x1b[32mAll minilib object compiled\x1b[0m\n"
	@ar -rc $(NAME) $(OBJ)
	@printf ">  \x1b[32m$(NAME) compiled \x1b[0m\n"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@printf ">  \x1b[31m$(NAME) deleted\x1b[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re