SRCS_OPE = 		srcs/operations/operations_a.c \
		srcs/operations/operations_b.c \
		srcs/operations/operations_twin.c \
		srcs/push_swap/initialization.c \
		srcs/push_swap/tools.c \
		srcs/push_swap/algo_tools.c \
		srcs/push_swap/algo.c \
		srcs/push_swap/tools2.c \
		srcs/push_swap/print_ope.c \
		srcs/push_swap/sort_three_a.c \
		srcs/push_swap/sort_three_b.c \
		srcs/push_swap/reduce_ope.c \
		srcs/push_swap/reduce_tools.c

SRCS_SWAP = 	srcs/push_swap/push_swap.c

SRCS_CHECK =	srcs/checker/checker.c

OBJS_OPE = 		${SRCS_OPE:.c=.o}

OBJS_SWAP = 	${SRCS_SWAP:.c=.o}

OBJS_CHECK	=	${SRCS_CHECK:.c=.o}

INCS	=	-I ./includes -I libft/includes/

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all:		push_swap checker

.c.o:
			${CC} ${CFLAGS} ${INCS} -c $< -o $@ ${INCS}

push_swap:	${OBJS_SWAP} ${OBJS_OPE}
			${MAKE} -C libft
			${CC} ${CFLAGS} ${INCS} ${OBJS_SWAP} ${OBJS_OPE} -o push_swap libft/libft.a

checker:	${OBJS_CHECK} ${OBJS_OPE}
			${MAKE} -C libft
			${CC} ${CFLAGS} ${INCS} ${OBJS_CHECK} ${OBJS_OPE} -o checker libft/libft.a

clean:
			${RM} ${OBJS_SWAP} ${OBJS_CHECK} ${OBJS_OPE}
			${MAKE} -C libft clean

fclean:		clean
			${RM} ${OBJS_SWAP} ${OBJS_CHECK} ${OBJS_OPE} push_swap checker
			${MAKE} -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re
