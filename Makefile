SRCS = ft_printf.c $(wildcard ./libft/srcs/*.c)

INC = ./

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o} 

LIB = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ${INC}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

all: 	${LIB}

clean:	
		rm -f ${OBJS}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

.PHONY: all clean fclean re 