SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall -O3

complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "\033[36mCleaning complete\033[0m"

SRC_NAME  = ft_strdup2.c \
			ft_abs.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_capitalize.c \
			ft_chartostr.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_isxdigit.c \
			ft_itoa.c \
			ft_ltoa.c \
			ft_lltoa.c \
			ft_itoabase.c \
			ft_ltoabase.c \
			ft_lltoabase.c \
			ft_lowercase.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstpush.c \
			ft_lstsize.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_pow.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putwchar.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strchri.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcount_if.c \
			ft_strcpy.c \
			ft_strcut.c \
			ft_strdel.c \
			ft_strdjoin.c \
			ft_strdup.c \
			ft_strdupcat.c \
			ft_strequ.c \
			ft_strins.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strljoin.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strnchri.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrjoin.c \
			ft_strset.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_utoabase.c \
			ft_ultoabase.c \
			ft_ulltoabase.c \
			ft_wcslen.c \
			ft_wstrdup.c \
			printf_convchr.c \
			printf_convnum.c \
			printf_convptr.c \
			printf_convstr.c \
			printf_convhtg.c \
			printf_flag.c \
			printf_flag2.c \
			printf_flags.c \
			printf_format.c \
			printf_print.c \
			printf_print_wchar.c \
			printf_struct.c \
			printf_utils.c \
			printf_wcharutils.c \
			ft_printf.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33mBuilding Printf..\033[0m"
	@ar rc $(NAME) $(OBJ)
	@echo "Compiling sources into a Library.."
	@ranlib $(NAME)
	$(complete)

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir ./objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "**************************************"
	@echo "\033[33mCleaning process for Printf engaged..\033[0m"
	@echo "Removing Printf binaries.."
	@rm -rf ./objs
	$(cleaning)

fclean: clean
	@echo "\033[33mCleaning library and program..\033[0m"
	@echo "Removing library named libftprintf.."
	@rm -f $(NAME)
	$(cleaning)
	@echo "**************************************"

re: fclean all
