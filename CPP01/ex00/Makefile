NAME = Zombie

SRC	= main.cpp newZombie.cpp Zombie.cpp randomChump.cpp

HEADERS = Zombie.hpp

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