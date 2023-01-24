#цели all, clean, test, s21_matrix_oop.a
CC = g++ 
FLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = $(wildcard s21*.cc)
OBJ_FILES = $(patsubst %.cc,%.o,$(SRCS))
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
THIS_FILE := $(lastword $(MAKEFILE_LIST))
REPORT = @mkdir -p report

OS = $(shell uname)
ifeq ("$(OS)", "Linux")
    TEST_FLAGS = -lcheck  -pthread -lrt -lm -lsubunit
    LEAKS_RUN = valgrind ./test
else
    TEST_FLAGS = -lcheck
    LEAKS_RUN = CK_FORK=no leaks -atExit -- ./test
endif


run: clean main.cc $(SRCS) s21_matrix_oop.h
#	clang++ s21_matrix_oop.cc -o run
	$(CC) $(FLAGS) $(SRCS) main.cc -o run -g
	./run

all: clean s21_matrix_oop.a test

s21_matrix_oop.a: $(OBJ_FILES)
	

test: 

gcov_report: clean test

clean_src:
	rm -rf *.gcda *.gcno *.gcov test.info report

clean: 
	rm -rf s21_matrix_oop.a run run.dSYM .clang-format

.PHONY:
	all, clean, test, gcov_report, s21_matrix_oop.a

push:
	git push origin develop

leaks: test
	$(LEAKS_RUN)
	@$(MAKE) -f $(THIS_FILE) clean_src

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i s21*.cc  s21*.h
	clang-format -n s21*.cc  s21*.h


cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem s21*.cc
