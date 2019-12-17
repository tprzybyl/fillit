# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 11:36:22 by tprzybyl     #+#   ##    ##    #+#        #
#    Updated: 2018/10/29 19:20:34 by mjalenqu    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC =	ft_analyse.c\
		ft_backtracking.c\
		ft_tetriminos.c\
		main.c\
		ft_scan.c

OBJ = $(subst .c,.o,$(SRC))

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[0;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(DARK_BLUE)\nFichiers de "$(NAME)" compilés\n"
	@echo "$(LIGHT_GREEN)Compilation de la Libft : "
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft
	@echo "$(FLASH_GREEN)Programme "$(NAME)" compilé et prêt à l'usage !\n"

%.o: %.c fillit.h
	@gcc $(FLAGS) -I libft/includes -o $@ -c $<
	@echo "$(DARK_BLUE).\c"

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re: fclean all
