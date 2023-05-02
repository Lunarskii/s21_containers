CC							= g++
CFLAGS						= -Wall -Werror -Wextra -std=c++17 -pedantic -g
LDFLAGS						= $(shell pkg-config --cflags --libs gtest)
GCOV_FLAGS					= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS				= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

SRC_TESTS					:= $(wildcard tests/*.cpp)

all: test clean

test: $(SRC_TESTS)
	$(CC) $(SRC_TESTS) -o test $(LDFLAGS)
	./test

clean:
	rm -rf test
	rm -rf report
	rm -rf *.info
	rm -rf valgrind.txt

gcov_report: $(SRC_TESTS)
	$(CC) $(SRC_TESTS) -o test --coverage $(SRC_PROJECT) $(LDFLAGS)
	./test
	lcov -t "test" -o gcov.info --no-external -c -d .
	genhtml -o report gcov.info
	rm -rf ./*.gc*

open: 
	open report/index.html

valgrind: test
	valgrind $(VALGRIND_FLAGS) ./test
	! grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clang:
	clang-format --style=google -i $(SRC_PROJECT_DIR)*
	clang-format --style=google -i $(SRC_TEST_DIR)*

.PHONY: all clean rebuild open clang valgrind docker
