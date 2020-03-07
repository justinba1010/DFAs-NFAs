# I'm lazy, if you're reading this disregard the minimal makefile

CC = g++
FLAGS = -std=c++11

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

main : main.o
	$(LINK) $@ $^

main.o : main.cc
	$(COMPILE) $<

clean:
	rm -rf *.o main
