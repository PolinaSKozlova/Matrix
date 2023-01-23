#цели all, clean, test, s21_matrix_oop.a
CC = g++ 
FLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = $(wildcard s21*.cc) $(wildcard **/*s21*.cc)
OBJ_FILES = $(patsubst %.cc,%.o,$(SRCS))
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

run: main.cc $(SRCS) s21_matrix_oop.h
#	clang++ s21_matrix_oop.cc -o run
	$(CC) $(FLAGS) $(SRCS) main.cc -o run -g
	./run

all: clean s21_matrix_oop.a test

s21_matrix_oop.a: $(OBJ_FILES)
	

test: 

gcov_report: clean test

clean: 
	rm -rf s21_matrix_oop.a run run.dSYM 

push:
	git push origin develop