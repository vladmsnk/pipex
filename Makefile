NAME = pipex

SRC = main.c pipex_utils.c

OBJ = $(SRC:.c=.o)

HDRS = pipex.h

LIBFTDIR = ./libft/

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

RM = rm -f

LIBFT_NAME = libft.a

LIBFT = $(addprefix ${LIBFTDIR}, ${LIBFT_NAME})

all:	${LIBFT} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

$(NAME): $(HDRS) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -L ${LIBFTDIR} -lft -o $(NAME)

clean:
	${RM} $(OBJ)
	${MAKE} clean -C ${LIBFTDIR}


fclean:		clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}


re:	fclean all

.PHONY: all clean fclean 
