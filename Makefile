CC = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -g
FLAGS = -lgtest -lpthread --coverage -fprofile-arcs -ftest-coverage -fPIC -O0 

.PHONY: clean fclean tclean

all: main.o hangman.o wordreader.o
	@$(CC) main.o hangman.o wordreader.o -o hangman

main.o: main.cpp

hangman.o: hangman.cpp

wordreader.o: wordreader.cpp

lint: *.cpp *.hpp
	clang-format --Werror --dry-run *.hpp *.cpp

coverage: hangman.cpp wordreader.cpp test.cpp
	$(CC) -c $(FLAGS) hangman.cpp
	$(CC) -c $(FLAGS) wordreader.cpp
	$(CC) -c $(FLAGS) test.cpp

test: coverage
	@$(CC) test.o hangman.o wordreader.o $(FLAGS) -o tmp
	./tmp
	gcovr -r .
	$(RM) tmp *.o *.gcda *.gcno

clean:
	rm *.o

fclean:
	$(RM) *.o hangman

tclean:
	$(RM) *.o rm test
