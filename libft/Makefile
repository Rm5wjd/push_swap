NAME = libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

SRCS = ft_isalpha.c ft_memcpy.c ft_strlcpy.c ft_toupper.c ft_isascii.c ft_memmove.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_memset.c ft_strncmp.c ft_bzero.c ft_isprint.c ft_strchr.c ft_strnstr.c ft_calloc.c ft_memchr.c ft_strdup.c ft_strrchr.c ft_isalnum.c ft_memcmp.c ft_strlcat.c ft_tolower.c ft_substr.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c ft_split.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJS = ${SRCS:.c=.o} 
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

ifdef WITH_BONUS
	OBJS_FILES = $(OBJS) $(BONUS_OBJS)
else
	OBJS_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	ar -rcs $@ $^

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

