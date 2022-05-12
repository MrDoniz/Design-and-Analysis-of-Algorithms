CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cc
F2 = fibonacci_words_exercise.cc

IDIR = ../include/
ODIR = ../src/
LDIR = ../lib/

PROGRAM = fibonacci_words_exercise

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	//g++ -std=c++14 -g -Wall estructura1.cpp -o program