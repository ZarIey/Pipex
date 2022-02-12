NAME 	= pipex			
SRCS 	= pipex.c path_pipex.c
OBJS 	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
				
all			:	${NAME}

${NAME} 	:	${OBJS}
				echo "\033[32;1m----Compiling lib----"
				make re -C ./libft
				$(CC) ${OBJS} -Llibft -lft -o ${NAME}
				echo "\033[32mPipex Compiled!\n"

clean		:	make clean -C ./libft
				rm -rf ${OBJS} ${OBJS_B}
				echo "\033[32;1mDeleting all .o\n"

fclean 		:	clean
				rm -rf ${NAME}
				echo "/033[32;1mDeleting everything !\n"

re 			:	fclean all
				echo "/033[32;1m"Make reset !\n"

.PHONY: clean re all fclean