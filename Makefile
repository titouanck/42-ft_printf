SRCS = $(wildcard ./libft/libc/*.c) $(wildcard ./libft/additional/*.c) $(wildcard ./libft/others/*.c) $(wildcard ./*.c)

SRCSBONUS = ${SRCS} $(wildcard ./libft/bonus/*.c) 

INC = ./includes/

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o} 

LIB = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ${INC}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

bonus:	${OBJSBONUS}
		ar -rsc ${LIB} ${OBJSBONUS}

all: 	${LIB}

clean:	
		rm -f ${OBJSBONUS}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

.PHONY: all clean fclean re 