NAME = minilib.a

FILES = mini_charfind \
	mini_cut_to \
	mini_ft_split \
	mini_is_intab \
	mini_lrstrcmp \
	mini_split \
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
	mini_tokenfirst

S = $(foreach f, $(FILES), $(f).c)
OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I../headers

all: $(NAME)

$(NAME): $(OBJ)
	@printf ">  \x1b[32mAll minilib object compiled\x1b[0m\n"
	@ar -rc $(NAME) $(OBJ)
	@printf ">  \x1b[32m$(NAME) compiled \x1b[0m\n"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $< -fsanitize=address -g

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@printf ">  \x1b[31m$(NAME) deleted\x1b[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re