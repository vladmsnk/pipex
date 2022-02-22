NAME = pipex

SRC = bonus.c pipex_utils_bonus1.c pipex_utils_bonus2.c pipex_utils_bonus3.c here_doc.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

HDRS = pipex_bonus.h get_next_line/get_next_line.h

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
