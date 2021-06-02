CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -g
FLAGS = --coverage -fPIC -O0
LDLIBS = -lgtest -lpthread

hangman: main.cpp hangman.cpp wordreader.cpp

.PHONY: lint
lint: *.cpp *.hpp
	clang-format --Werror --dry-run *.hpp *.cpp

.PHONY: coverage
coverage: hangman.cpp wordreader.cpp test.cpp
	g++ -c $(FLAGS) hangman.cpp
	g++ -c $(FLAGS) wordreader.cpp
	g++ -c $(FLAGS) test.cpp

.PHONY: test
test: coverage
	g++ test.o hangman.o wordreader.o $(FLAGS) $(LDLIBS) -o tmp
	./tmp
	gcovr -r .
	$(RM) tmp *.o *.gcda *.gcno

.PHONY: clean
clean:
	$(RM) *.o hangman
