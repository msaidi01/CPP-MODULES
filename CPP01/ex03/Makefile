NAME = violence

SRC	= main.cpp  Weapon.cpp HumanA.cpp HumanB.cpp

Headers = HumanA.hpp HumanB.hpp Weapon.hpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CC	 = c++

RM 	 = rm -rf

OBJS = $(SRC:.cpp=.o)

%.o : %.cpp $(Headers)
	$(CC) $(CPPFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS) $(Headers)
	$(CC) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re