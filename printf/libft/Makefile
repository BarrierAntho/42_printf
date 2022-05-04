SEP_P		=	"------------------------------"

SEP_SP		=	"******************************"

SRCS		= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			  	ft_strlen.c\
			  	ft_strlcpy.c ft_strlcat.c  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c\
			  	ft_toupper.c ft_tolower.c\
			  	ft_memset.c ft_bzero.c ft_calloc.c\
			  	ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
			  	ft_atoi.c ft_itoa.c	ft_split.c\
			  	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_striteri.c ft_strmapi.c\
			  	ft_putchar_fd.c ft_putnchar_fd.c ft_putstr_fd.c ft_putnstr_fd.c ft_putendl_fd.c\
				ft_intlen.c ft_unintlen.c ft_hexalen.c ft_pointerlen.c\
				ft_check_base.c ft_check_in_base.c\
				ft_atoi_base.c\
				ft_puti_base_fd.c ft_putu_base_fd.c ft_putn_rfd.c\

OBJS		= 	${SRCS:.c=.o}

INCLUDES	= 	-I .

CC			= 	gcc

CFLAGS		= 	-Werror -Wall -Wextra

RM			= 	rm -f

NAME		= 	libft.a

%.o : %.c
				${CC} ${CFLAGS} ${INCLUDES} -c $*.c -o $@

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

norme:
				@echo ${SEP_P}
				norminette

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

.PHONY:			all clean fclean re norme check
