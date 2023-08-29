name = pathfinder
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRC = 	test.c\
		read_2.c \
		read.c \
		utils1.c \
		utils2.c \
		utils3.c \
		utils4.c

INCLUDES=./
obj= $(SRC:.c=.o)

RED = \033[0;31m

GREEN = \033[0;32m

BLUE = \033[0;34m

CYAN = \033[0;36m

PURPLE = \033[0;35m

MAGENTA = \033[0;95m

Default = \033[0m

all: $(name)
.c.o:
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(name):
	@gcc -Wall -Wextra -Werror $(SRC) -I $(INCLUDES)  -o $(name)
	@echo "$(PURPLE)./$(MAGENTA)$(name)$(CYAN) compiled successfully !$(Default) 🎉"

clean:
	@rm -rf object
	@echo "$(RED)$(name)$(CYAN) object files deleted !$(Default) 🗑️"


fclean: clean
	@rm -rf $(name)
	@echo "$(RED)$(name)$(CYAN) deleted !$(Default) 🗑️"

re: fclean all

.PHONY: all clean fclean re 