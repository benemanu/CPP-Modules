CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
NAME		= ./execute
NAME_SHORT	= execute

INCS_DIR	= ./includes/
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

SRCS_DIR 	= ./sources/
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS_DIR	= ./objects/
OBJS		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.cpp
			@mkdir -p $(OBJS_DIR)
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CC) $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean		:
ifeq ($(OBJS_DIR), ./)
			@$(RM) $(OBJS)
else
			@$(RM) $(OBJS_DIR)
endif
			@$(RM) *_shrubbery

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re