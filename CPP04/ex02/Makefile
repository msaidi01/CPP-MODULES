NAME = abstract

SRC	= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

CC	 = c++

RM 	 = rm -rf

OBJS = $(SRC:.cpp=.o)

%.o : %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
