NAME	= libftprintf.a
AR		= ar rc
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRCS	= baseP.c baseSC.c baseSixteen.c baseTen.c ft_printf.c 
OBJS	= $(SRCS:%.c=%.o)

all: ${NAME}

${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all