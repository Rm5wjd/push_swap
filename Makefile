NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Werror -Wall -Wextra
DEBUG_FLAGS = -g
LIB = libft.a
LIB_DIR = ./libft

SRCS = checker.c greedy.c node_manager.c operations.c parsing.c sorting.c stack_manager.c utils.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d) $(BONUS).d $(NAME).d

$(NAME) :: $(LIB)
$(NAME) :: $(OBJS)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -MMD -o $(NAME) $^ $(LIB) $(DEBUG_FLAGS)

all : $(NAME)

bonus : $(BONUS)

$(BONUS) :: $(LIB)
$(BONUS) :: $(OBJS)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -MMD -o $(BONUS) $^ $(LIB) $(DEBUG_FLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c -I. -MMD $< $(DEBUG_FLAGS)

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(LIB) $(DEPS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(BONUS)

re :
	make fclean
	make all

ifeq "$(filter clean fclean re,$(MAKECMDGOALS))" ""
-include $(DEPS)
endif

.PHONY : clean fclean re
