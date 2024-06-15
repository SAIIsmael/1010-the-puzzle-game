PROG=1010!
CC=g++
FLAGS=-lncurses
SRCS=*.cpp
EXT=*.o
OBJS=$(SRCS:.c=.o)

all:$(OBJS)
	${CC} -o $(PROG) $(OBJS) $(FLAGS)

%.o:%.c
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -f $(EXT) $(PROG)