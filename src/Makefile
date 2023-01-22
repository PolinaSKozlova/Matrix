#цели all, clean, test, s21_matrix_oop.a

run: main.cc s21_matrix_oop.cc s21_matrix_oop.h
#	clang++ s21_matrix_oop.cc -o run
	g++ -std=c++17 s21_matrix_oop.cc main.cc -o run -g
	./run

all: clean s21_matrix_oop.a test

s21_matrix_oop.a:
	

test: 


clean: 
	rm -rf s21_matrix_oop.a run run.dSYM 

push:
	git push origin develop