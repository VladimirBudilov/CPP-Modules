NAME 		=	ex00
CC 			=	c++
CPPFLAGS 	=	-std=c++98 -Wall -Wextra -Werror -pedantic
SRCS 		=	$(wildcard *.cpp)
HEADER		=	$(wildcard *.h)
OBJS 		=	$(patsubst %.cpp, %.o, $(SRCS))
RM 			= 	rm -fr

all: $(NAME) run

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@tput setaf 2 && printf "$(NAME) sucessfully created.\n\n\n"
	@tput setaf 255

%.o: %.cpp $(HEADER)
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@tput setaf 3 && printf "created $(notdir $@)\n"
	@tput setaf 255

runPrepare: $(NAME)
	@./$(NAME)

run : runPrepare fclean

clean:
	@$(RM) $(OBJS)
	@tput setaf 255

fclean: clean
	@$(RM) $(NAME)


.PHONY: all clean fclean re me bonus