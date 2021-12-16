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

CHECKER	=	checker

PUSH_SWAP = push_swap

OBJS_OPE = 		${SRCS_OPE:.c=.o}

OBJS_SWAP = 	${SRCS_SWAP:.c=.o}

OBJS_CHECK	=	${SRCS_CHECK:.c=.o}

INCS	=	-I ./includes -I libft/includes/

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

all:		${PUSH_SWAP} ${CHECKER}

.c.o:
				@echo "Compiling ${_YELLOW}${_BOLD}$<${_END}..."
				@${CC} ${CFLAGS} ${INCS} -c $< -o $@ ${INCS}

${PUSH_SWAP}:	${OBJS_SWAP} ${OBJS_OPE}
				@echo "Compiling ${_GREEN}${_BOLD}libft${_END}..."
				@${MAKE} -C libft >/dev/null
				@echo "Compiling ${_CYAN}${_BOLD}push_swap${_END}..."
				@${CC} ${CFLAGS} ${INCS} ${OBJS_SWAP} ${OBJS_OPE} -o ${PUSH_SWAP} libft/libft.a

${CHECKER}:		${OBJS_CHECK} ${OBJS_OPE}
				@echo "Compiling ${_GREEN}${_BOLD}libft${_END}..."
				@echo "Compiling ${_CYAN}${_BOLD}checker${_END}..."
				@${CC} ${CFLAGS} ${INCS} ${OBJS_CHECK} ${OBJS_OPE} -o ${CHECKER} libft/libft.a

clean:
				@echo "Deleting ${_RED}${_BOLD}binary files${_END}..."
				@${RM} ${OBJS_SWAP} ${OBJS_CHECK} ${OBJS_OPE}
				@echo "Deleting ${_RED}${_BOLD}libft binary files${_END}..."
				@${MAKE} -C libft clean >/dev/null

fclean:			clean
				@echo "Deleting ${_RED}${_BOLD}push_swap and checker${_END}..."
				@${RM} ${OBJS_SWAP} ${OBJS_CHECK} ${OBJS_OPE} ${PUSH_SWAP} ${CHECKER}
				@echo "Deleting ${_RED}${_BOLD}libft librairy${_END}..."
				@${MAKE} -C libft fclean >/dev/null

re:				fclean all

.PHONY:			all clean fclean re
