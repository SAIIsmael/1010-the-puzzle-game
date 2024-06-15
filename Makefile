NAME	=	1010

CXX	=	g++

LDFLAGS	=	-lncurses

SRCS	=	src/main.cpp  \
		src/board.cpp \
		src/window.cpp\
		src/choice.cpp\
		src/score.cpp\
		src/myprogram.cpp


CXXFLAGS=	-W -Wall -ansi -pedantic -I./inc

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
