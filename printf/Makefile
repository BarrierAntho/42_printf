SEP_P		=	"------------------------------"

SEP_SP		=	"******************************"

DIR_S		=	srcs

DIR_LIBFT	=	libft

SOURCES		=	ft_printf.c\
				ft_printf_lstformat.c ft_printf_getformat.c ft_printf_purgeformat.c\
				ft_printf_argnew.c ft_printf_argadd_back.c ft_printf_argdel_front.c ft_printf_argclear.c\
				ft_printf_putformat.c ft_printf_putc.c ft_printf_puts.c ft_printf_putd.c ft_printf_putp.c ft_printf_putu.c ft_printf_putx.c ft_printf_putper.c

SRCS		= 	${addprefix ${DIR_S}/, ${SOURCES}}

OBJS		= 	${SRCS:.c=.o}

INCLUDES	=	includes

CC			= 	gcc

CFLAGS		= 	-Werror -Wall -Wextra

RM			= 	rm -rf

NAME		= 	libftprintf.a

NAME_LIBFT	=	libft.a

%.o : %.c
				${CC} ${CFLAGS} -I ${INCLUDES} -I ${DIR_LIBFT} -c $< -o $@

${NAME}:		${OBJS}
				@cp ${DIR_LIBFT}/libft.h ${INCLUDES}/
				@make -C ${DIR_LIBFT}
				@cp ${DIR_LIBFT}/${NAME_LIBFT} ./${NAME}
				ar rc ${NAME} ${OBJS}
				@ranlib	${NAME}

all:			${NAME}

clean:			
				${RM} ${OBJS}
				@make clean -C ${DIR_LIBFT}

fclean:			clean
				${RM} ${NAME}
				@make fclean -C ${DIR_LIBFT}

re:				fclean all
				@make re -C ${DIR_LIBFT}

bonus:			${NAME}

norme:			
				@echo ${SEP_P}
				norminette ${DIR_LIBFT}
				@echo ${SEP_P}
				norminette ${DIR_S}
				@echo ${SEP_P}
				norminette ${INCLUDES}

check:
				@echo ${SEP_P}
				@echo "Check forbidden function"
				grep -RiEn 'main' .
				@echo ${SEP_SP}
				grep -RiEn '[^_]printf' .
				@echo ${SEP_SP}
				grep -RiEn '[^_]strlen' .
				@echo ${SEP_SP}
				grep -RiEn '[^_]atoi' .
				@echo ${SEP_SP}
				grep -RiEn '[^_]putchar' .
				@echo ${SEP_SP}
				grep -RiEn '[^_]putstr' .
				@echo ${SEP_P}
				@echo "Check exec (a.out)"
				@find . -type f -name "a.out" -print
				@echo ${SEP_P}
				@echo "Check swp"
				@find . -type f -name "*.swp" -print
				@echo ${SEP_P}
				@echo "Check .o"
				@find . -type f -name "*.o" -print

.PHONY:			all bonus clean fclean re bonus norme check
