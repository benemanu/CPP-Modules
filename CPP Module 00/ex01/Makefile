NAME        = PhoneBook

CC            = c++
FLAGS        = -Wall -Wextra -Werror -std=c++98 -g
RM            = rm -rf

OBJDIR = .objFiles

FILES        =     main \
		   Contacts \
		   PhoneBook

SRC            = $(FILES:=.cpp)
OBJ            = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER        = Contacts.hpp PhoneBook.hpp

#Colors:
GREEN        =    \e[92;5;118m
YELLOW        =    \e[93;5;226m
GRAY        =    \e[33;2;37m
RESET        =    \e[0m
CURSIVE        =    \e[33;3m

.PHONY: all clean fclean re val run

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) valgrind-out.txt
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

val: all
	make -C ./ clean
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./$(NAME) 
	code valgrind-out.txt

run:
	./$(NAME)
