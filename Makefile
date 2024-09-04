# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 10:27:39 by mamichal          #+#    #+#              #
#    Updated: 2024/09/04 18:58:26 by mamichal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -fr
INCLUDES = ./includes/pipex.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = src/cleanup.c \
		src/env_paths.c \
		src/files.c \
		src/main.c \
		src/parse.c \
		src/process.c

OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -include $(INCLUDES)

${NAME}: $(OBJS) ${LIBFT}
	${CC} ${FLAGS} -o ${NAME} $(OBJS) ${LIBFT} -include $(INCLUDES)
	echo Compiling Executable

all: ${NAME}

bonus: ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH} all

clean:
	${RM} *.o */*.o */*/*.o
	make -C ${LIBFT_PATH} fclean
	echo Only Exec Left

fclean: clean
	${RM} ${NAME}
	echo All Clean

re: fclean all

.SILENT:

.PHONY: all clean fclean re
