vpath %.cpp s21_containers.h/list
vpath %.cpp s21_containers.h/map
vpath %.cpp s21_containers.h/queue
vpath %.cpp s21_containers.h/set
vpath %.cpp s21_containers.h/stack
vpath %.cpp s21_containers.h/vector
vpath %.cpp s21_containersplus.h/array
vpath %.cpp s21_containersplus.h/multiset
vpath %.cpp tests

CC							= g++
CFLAGS						= -Wall -Werror -Wextra -std=c++17 -pedantic -g
LDFLAGS						= $(shell pkg-config --cflags --libs gtest)
GCOV_FLAGS					= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS				= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

SRC_CONTAINERS_DIR			= s21_containers.h/
SRC_CONTAINERSPLUS_DIR		= s21_containersplus.h/
SRC_TESTS_DIR				= tests/
OBJ_CONTAINERS_DIR			= ../obj/containers/
OBJ_CONTAINERSPLUS_DIR		= ../obj/containersplus/
OBJ_TESTS_DIR				= ../obj/tests/

CONTAINERS_LIBRARY			= s21_containers.a
CONTAINERSPLUS_LIBRARY		= s21_containersplus.a
BUILD_FOLDERS				:= $(shell mkdir -p $(OBJ_CONTAINERS_DIR); mkdir -p $(OBJ_CONTAINERSPLUS_DIR); mkdir -p $(OBJ_TESTS_DIR))
SRC_CONTAINERS				:= $(wildcard $(SRC_CONTAINERS_DIR)list/*.cpp $(SRC_CONTAINERS_DIR)map/*.cpp $(SRC_CONTAINERS_DIR)queue/*.cpp $(SRC_CONTAINERS_DIR)set/*.cpp $(SRC_CONTAINERS_DIR)stack/*.cpp $(SRC_CONTAINERS_DIR)vector/*.cpp)
SRC_CONTAINERSPLUS			:= $(wildcard $(SRC_CONTAINERSPLUS_DIR)array/*.cpp $(SRC_CONTAINERSPLUS_DIR)multiset/*.cpp)
SRC_TESTS					:= $(wildcard $(SRC_TESTS_DIR)*.cpp)
OBJ_CONTAINERS				:= $(patsubst %.cpp, $(OBJ_CONTAINERS_DIR)%.o, $(notdir $(SRC_CONTAINERS)))
OBJ_CONTAINERSPLUS			:= $(patsubst %.cpp, $(OBJ_CONTAINERSPLUS_DIR)%.o, $(notdir $(SRC_CONTAINERSPLUS)))
OBJ_TESTS					:= $(patsubst %.cpp, $(OBJ_TESTS_DIR)%.o, $(notdir $(SRC_TESTS)))

all: $(CONTAINERS_LIBRARY) test clean

$(CONTAINERS_LIBRARY): $(OBJ_CONTAINERS)
	ar rc $(CONTAINERS_LIBRARY) $(OBJ_CONTAINERS)
	ranlib $(CONTAINERS_LIBRARY)

$(CONTAINERSPLUS_LIBRARY): $(OBJ_CONTAINERSPLUS)
	ar rc $(CONTAINERSPLUS_LIBRARY) $(OBJ_CONTAINERSPLUS)
	ranlib $(CONTAINERSPLUS_LIBRARY)

test: $(CONTAINERS_LIBRARY) $(CONTAINERSPLUS_LIBRARY) $(OBJ_TESTS)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o test $(CONTAINERS_LIBRARY) $(CONTAINERSPLUS_LIBRARY) $(LDFLAGS)
	./test

# gcov_report: $(OBJ_TEST)
# 	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(LDFLAGS)
# 	./test
# 	lcov -t "test" -o gcov.info -c -d .
# 	genhtml -o report gcov.info
# 	rm -rf ./*.gc*

$(OBJ_CONTAINERS_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CONTAINERSPLUS_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TESTS_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ../obj/
	rm -rf test
	rm -rf *.a
	rm -rf report
	rm -rf *.info
	rm -rf valgrind.txt

open: 
	open report/index.html

valgrind: test
	valgrind $(VALGRIND_FLAGS) ./test
	! grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clang:
	clang-format --style=google -i $(SRC_PROJECT_DIR)*
	clang-format --style=google -i $(SRC_TEST_DIR)*

.PHONY: all clean rebuild open clang valgrind docker
