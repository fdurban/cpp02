NAME = fixed

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = Fixed.cpp main.cpp

OBJS = $(SRC:.cpp=.o)

all:$(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -o $@ -c $<

$(NAME):$(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(OBJS) $(NAME)
re: fclean all

