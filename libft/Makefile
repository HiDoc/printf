SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra

complete = @echo "\033[92mComplete\033[0m\n"

SRC_NAME = ft_putchar.c \
		   ft_strset.c \
		   ft_abs.c \
		   ft_strcount_if.c \
		   ft_uitoa.c \
		   ft_itoabase.c \
		   ft_strljoin.c \
		   ft_strrjoin.c \
		   ft_strdjoin.c \
		   ft_strchri.c \
		   ft_strdupcat.c \
		   ft_lstsize.c \
		   ft_strndup.c \
		   ft_pow.c \
		   ft_isxdigit.c \
		   ft_lowercase.c \
		   ft_capitalize.c \
		   ft_lstpush.c \
		   ft_isspace.c \
		   ft_putstr.c \
		   ft_strlen.c \
		   ft_putnbr.c \
		   ft_isalpha.c \
		   ft_isalnum.c \
		   ft_isprint.c \
		   ft_isdigit.c \
		   ft_isascii.c \
		   ft_atoi.c \
		   ft_itoa.c \
		   ft_strcat.c \
		   ft_bzero.c \
		   ft_lstadd.c \
		   ft_lstdel.c \
		   ft_lstdelone.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_lstnew.c \
		   ft_memalloc.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memdel.c \
		   ft_memmove.c \
		   ft_memset.c \
		   ft_putchar_fd.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   ft_putstr_fd.c \
		   ft_strchr.c \
		   ft_strclr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdel.c \
		   ft_strdup.c \
		   ft_strequ.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strjoin.c \
		   ft_strlcat.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strnequ.c \
		   ft_strnew.c \
		   ft_strnstr.c \
		   ft_strrchr.c \
		   ft_strsplit.c \
		   ft_strstr.c \
		   ft_strsub.c \
		   ft_strtrim.c \
		   ft_tolower.c \
		   ft_toupper.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Generating objects for the library.."
	@echo "Generating the library.."
	@ar rc $(NAME) $(OBJ)
	@echo "Indexing the library.."
	@ranlib $(NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@echo "Objects have been removed"

fclean : clean
	@rm -f $(NAME)
	@echo "Library have been removed"
	$(complete)

re : fclean all
