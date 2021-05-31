CC = g++
FLAGS = -std=c++17 -Wall -Wextra -Werror -g
FLAGS2 = --coverage -fprofile-arcs -ftest-coverage -fPIC -O0
GFLAG = -lgtest -lpthread

.PHONY:
	clean fclean tclean

all: main.o hangman.o wordreader.o
	@$(CC) main.o hangman.o wordreader.o -o hangman

main.o: main.cpp
	@$(CC) -c $(FLAGS) main.cpp

hangman.o: hangman.cpp
	@$(CC) -c $(FLAGS) hangman.cpp

wordreader.o: wordreader.cpp
	@$(CC) -c $(FLAGS) wordreader.cpp

test.o: test.cpp
	@$(CC) -c $(FLAGS) $(FLAGS2) test.cpp

lint: *.cpp *.hpp
	clang-tidy *.cpp *.hpp -checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus* --
	clang-format --Werror --dry-run *.hpp *.cpp

coverage: hangman.cpp wordreader.cpp
	@$(CC) -c $(FLAGS) $(FLAGS2) hangman.cpp
	@$(CC) -c $(FLAGS) $(FLAGS2) wordreader.cpp

test: test.o coverage
	@$(CC) test.o hangman.o wordreader.o $(FLAGS) $(GFLAG) $(FLAGS2) -o tmp
	./tmp
	gcovr -r .
	rm tmp
	rm *.o
	rm *.gcda
	rm *.gcno

clean:
	rm *.o

fclean:
	rm *.o
	rm hangman

tclean:
	rm *.o
	rm test