NAME = AMateria

SRC	= main.cpp AMateria.cpp Ice.cpp  Cure.cpp Character.cpp MateriaSource.cpp

HEADERS = AMateria.hpp Cure.hpp Ice.hpp Icharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp 

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
