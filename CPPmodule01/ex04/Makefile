NAME 		=	 Sed_is_for_losers
CC 			=	c++
CPPFLAGS 	=	-std=c++98 -Wall -Wextra -Werror
SRCS 		=	$(wildcard *.cpp)
HEADER		=	$(wildcard *.hpp)
OBJS 		=	$(patsubst %.cpp, %.o, $(SRCS))
RM 			= 	rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@tput setaf 2 && printf "$(NAME) sucessfully created.\n"
	@tput setaf 255

%.o: %.cpp $(HEADER)
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@tput setaf 3 && printf "created $(notdir $@)\n"
	@tput setaf 255

clean:
	@$(RM) $(OBJS)
	@tput setaf 928 && printf "clean  🗑\n"
	@tput setaf 255

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re me bonus
