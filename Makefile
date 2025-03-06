NAME	=	miniRT
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	miniRT \
			src/parsing/parser00 src/parsing/parser01 src/parsing/parser02 src/parsing/parser03 src/parsing/parser04 \
			src/parsing/parser05 src/parsing/parser06 \
			src/vectors/vectors00 src/vectors/vectors01 \
			src/scene/scene00 \

SRCS	=	$(addsuffix .c, ${SRC})
OBJS	=	$(SRCS:.c=.o)
LIBFT	=	libft/libft.a
MLX	=	-L./minilibx/ -lmlx -lX11 -lXext

all: ${NAME}

%.o: %.c
		@cc ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@make -s -C libft
	@make -s -C minilibx
	@cc ${CFLAGS} ${OBJS} -o ${NAME} ${MLX} ${LIBFT} -lm

clean:
	@make clean -s -C minilibx
	@make clean -s -C libft
	@rm -f ${OBJS}
	clear

fclean: clean
	@make fclean -s -C libft
	@rm -f ${NAME}
	clear

re: fclean all
	clear