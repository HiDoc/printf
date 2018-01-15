SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall

complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "\033[36mCleaning complete\033[0m"

SRC_NAME  = ft_format.c \
			ft_arguments.c \
			ft_printf.c \
			ft_flags.c \
			ft_precision.c \
			ft_field.c \
			struct.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB = -L./libft/ -lft
LIB_INC = -I./libft/includes/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH)) $(LIB_INC)

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33mLaunching Makefile for Libft..\033[0m"
	@make -C ./libft
	@echo "**************************************"
	@echo "\033[33mBuilding Printf..\033[0m"
	@ar rc $(NAME) $(OBJ)
	@echo "Compiling sources into a Library.."
	@ranlib $(NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "**************************************"
	@echo "\033[33mCleaning process for Libft engaged..\033[0m"
	@make clean -C ./libft
	$(cleaning)
	@echo "**************************************"
	@echo "\033[33mCleaning process for Printf engaged..\033[0m"
	@echo "Removing Printf binaries.."
	@rm -f $(OBJ)
	$(cleaning)

fclean: clean
	@echo "\033[33mCleaning library and program..\033[0m"
	@echo "Removing library named libftprintf.."
	@rm -f $(NAME)
	@make fclean -C ./libft
	$(cleaning)
	@echo "**************************************"

re: fclean all
