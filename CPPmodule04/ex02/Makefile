NAME 		=	ex01
CC 			=	c++
CPPFLAGS 	=	-std=c++98 -Wall -Wextra -Werror -pedantic
SRCS 		=	$(wildcard *.cpp)
HEADER		=	$(wildcard *.h)
OBJS 		=	$(patsubst %.cpp, %.o, $(SRCS))
RM 			= 	rm -fr

all: $(NAME) run

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@tput setaf 3 && printf "\n"
	@tput setaf 255

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@


runPrepare: $(NAME)
	@./$(NAME)

run : runPrepare fclean

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re me bonus