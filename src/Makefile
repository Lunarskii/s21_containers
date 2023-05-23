OS := $(shell uname)

ifeq ($(OS),Darwin) # Mac OS X
    INSTALL_CMD := brew install cmake
else ifeq ($(OS),Linux) # Linux
    INSTALL_CMD := sudo apt-get install cmake
else ifeq ($(OS),Windows_NT) # Windows
    INSTALL_CMD := choco install cmake
else
    $(error Unsupported operating system: $(OS))
endif

all: test

install:
	$(INSTALL_CMD)

test:
	cmake -B build
	make -C build s21_containers
	./build/s21_containers

clean:
	rm -rf build
	rm -rf coverage*

clang:
	clang-format --style=google -i s21_containers/binaryTree/*
	clang-format --style=google -i s21_containers/list/*
	clang-format --style=google -i s21_containers/map/*
	clang-format --style=google -i s21_containers/queue/*
	clang-format --style=google -i s21_containers/set/*
	clang-format --style=google -i s21_containers/stack/*
	clang-format --style=google -i s21_containers/vector/*
	clang-format --style=google -i s21_containersplus/array/*
	clang-format --style=google -i s21_containersplus/multiset/*
	clang-format --style=google -i tests/*

.PHONY: all test clean
