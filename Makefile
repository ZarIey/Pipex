NAME 	= pipex			
SRCS 	= pipex.c path_pipex.c
OBJS 	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
				
all			:	${NAME}

${NAME} 	:	${OBJS}
				@echo "\033[32m<< Compiling ... >>\033[33;1m"
				@make re -C ./libft
				@echo "\033[32mLibft Compiled !\n"
				@$(CC) ${OBJS} -Llibft -lft -o ${NAME}
				@echo "\033[32mPipex Compiled !\n"

clean		:	
				@echo "\033[32m<< clean process ... >>\033[33;1m"
				@make clean -C ./libft
				@rm -rf ${OBJS}
				@echo "\033[32;1mDeleting all '.o' files !\n"

fclean 		:	clean
				@echo "\033[32m<< fclean process ... >>\033[33;1m"
				@rm -rf ${NAME}
				@echo "\033[32;1mDeleting everything !\n"

re 			:	fclean all
				@echo "\033[32;1mReset made !\n"

.PHONY: clean re all fclean