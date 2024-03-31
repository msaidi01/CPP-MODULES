NAME = PmergeMe

SRC	= main.cpp PmergeMe.cpp

HEADER = PmergeMe.hpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CC	 = c++

RM 	 = rm -rf

OBJS = $(SRC:.cpp=.o)

%.o : %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re