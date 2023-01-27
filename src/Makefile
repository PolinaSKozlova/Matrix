#цели all, clean, test, s21_matrix_oop.a

CC=g++ -lstdc++ -std=c++17
FLAGS=-Wall -Wextra -Werror 
PROJECT_NAME=s21_matrix_oop
SRCS=$(wildcard s21*.cc)
OBJ_FILES=$(patsubst %.cc,%.o,$(SRCS))
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
THIS_FILE:= $(lastword $(MAKEFILE_LIST))
REPORT=@mkdir -p report

OS = $(shell uname)
ifeq ("$(OS)", "Linux")
    TEST_FLAGS=-lgtest -pthread -lrt -lm -lsubunit
    LEAKS_RUN=valgrind ./tests
else
    TEST_FLAGS=-lgtest -lm -pthread
    LEAKS_RUN=CK_FORK=no leaks -atExit -- ./tests
endif


run: clean run.cc $(SRCS) 
	$(CC) $(FLAGS) $(SRCS) run.cc -o run -g
	./run

all: clean $(PROJECT_NAME).a test

s21_matrix_oop.a: $(OBJ_FILES)
	ar rcs $(PROJECT_NAME).a $(OBJ_FILES)
	ranlib $(PROJECT_NAME).a 

test: clean test_matrix.cc $(SRCS)
	$(CC) $(FLAGS) $(SRCS) test_matrix.cc -o tests $(TEST_FLAGS)
	./tests

%.o:%.cc
	$(CC) -c $(FLAGS) $< -o $@ -I .

gcov_report: clean 
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(SRCS) test_matrix.cc -o tests $(TEST_FLAGS)		
	./tests
	lcov -t "gcov_report" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open ./report/index.html

clean_src:
	rm -rf *.gcda *.gcno *.gcov test.info report

clean: clean_src
	rm -rf s21_matrix_oop.a run run.dSYM .clang-format tests *.o

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
