# makefile
# 
# @author Ryan Morehouse
# @license MIT

OBJ = TerminalPrompt.o ChangeCalculator.o test.o
DEPS = TerminalPrompt.o ChangeCalculator.o
FLAGS = -Wall -lm
CC = g++
.SUFFIXES: .cpp .o

.cpp.o:
	g++ -o $@ $^ $(FLAGS)

all: $(OBJ)

TerminalPrompt.o: TerminalPrompt.cpp
	$(CC) -c -o $@ $< $(FLAGS)

ChangeCalculator.o: ChangeCalculator.cpp
	$(CC) -c -o $@ $< $(FLAGS)

test.o: test.cpp $(DEPS)

clean:
	\rm -f *.o
