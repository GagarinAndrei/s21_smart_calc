
CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11 
TST_CFLAGS:= -g $(STDFLAGS) -g
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
APP = build/SmartCalc.app 
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

TARGET=s21_matrix.a

SRC=$(wildcard model/*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})
# HEADER=$(wildcard s21_*.h)

PREF_TEST_SRC=./tests/
TEST_SRC=$(wildcard $(PREF_TEST_SRC)/*.c)
# TEST_OBJ = $(patsubst %.c,%.o, ${TEST_SRC})

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

.DELETE_ON_ERROR:
all: $(TARGET)

$(TARGET): ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	cp $@ lib$@
	make clean_obj

build:
	mkdir build
	cd ./build/ && qmake ../ && make  && mv qt_smart_calc.app SmartCalc.app

install: build
	@mkdir $(HOME)/Desktop/SmartCalc_v1.0/
	@cp -rf $(APP) $(HOME)/Desktop/SmartCalc_v1.0/
	make clean

uninstall:
	@rm -rf $(HOME)/Desktop/SmartCalc_v1.0/

dvi:
	open Calculator.html

dist:
	mkdir SmartCalc_v1.0/
	mkdir SmartCalc_v1.0/src
	cp Makefile *.c *.h *.pro *.cpp *.ui *.user SmartCalc_v1.0/src/
	tar cvzf SmartCalc_v1.0.tgz SmartCalc_v1.0/
	mv SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf SmartCalc_v1.0/

tests: $(TARGET)
ifeq ($(OS), Darwin)
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o unit_test $(LIBS)
else
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test

leaks: test
	leaks -atExit -- ./unit_test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test $(LIBS)
else
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test $(LIBS) $(LINUX_FLAGS)
endif
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

valgrind: $(TARGET)
	$(CC) $(TST_CFLAGS) ${TEST_SRC} $< -o test $(LIBS) $(LINUX_FLAGS)
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./test

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format; \
	clang-format -style=Google -n *.c *.h; \
	rm .clang-format

brew:
	eval /opt/goinfre/$(USERNAME)/homebrew/bin/brew shellenv; \
	brew update --force --quiet; \
	chmod -R go-w "$(brew --prefix)/share/zsh"

install_brew:
	cd /opt/goinfre/$(USERNAME); \
	mkdir homebrew; \
	git clone https://github.com/Homebrew/brew homebrew; \
	make brew

lcov:
	brew install lcov

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test
	rm -rf RESULT_VALGRIND.txt
	rm -rf *.o *.a
	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf s21_calc s21_test
	rm -rf ./build*

.PHONY: all clean check lcov



# # all, install, uninstall, clean, dvi, dist, test, gcov_report
# GCC=gcc -g
# CFALGS=-Wall -Werror -Wextra -std=c11
# SOURCES=model/*.c
# TESTS_SOURCES=tests/*.c 
# OBJECTS=$(SOURCES:.c=.o)

# ifeq ($(shell uname), Linux)
# 	CHECKFLAGS=-lcheck -lm -lpthread -lrt 
# #-lsubunit
# else
# 	CHECKFLAGS=-lcheck -lm -lpthread
# endif

# all: clean install gcov_report

# install:
# 	@mkdir -p /build
# 	@cd view && qmake && make && make clean && rm -rf Makefile && mv S21_SmartCalc_GUI.app ../../build/$(TARGET).app
# 	@cp -R ../build/$(TARGET).app ~/Desktop/$(TARGET).app

# uninstall:
# clean:
# dvi:
# dist:

# test: clean
# 	$(GCC) $(CFALGS) $(TESTS_SOURCES) $(SOURCES) $(CHECKFLAGS) -o s21_smart_calc
# 	./s21_smart_calc

# gcov_report: test
# 	$(GCC) $(CFALGS) $(TESTS_SOURCES) $(SOURCES) $(CHECKFLAGS) -fprofile-arcs -ftest-coverage -lgcov -o s21_smart_calc
# 	./s21_smart_calc
# 	lcov -t "./s21_smart_calc" -o report.info --no-external -c -d .
# 	genhtml -o report report.info
# 	open ./report/index.html

# clean:
# 	rm -rf s21_smart_calc *.a $(OBJECTS) a.out *.gcno *.gcda report report.info *.dSYM

# valgrind: clean test
# 	valgrind --tool=memcheck --leak-check=yes  ./s21_smart_calc

# leaks: clean test
# 	leaks -atExit -- ./s21_smart_calc | grep LEAK:

# clangn:
# 	clang-format -n -style=google $(SOURCES) headers/*.h $(TESTS_SOURCES) *.cpp	*.h view/*.cpp view/*.h

# clangi:
# 	clang-format -i -style=google $(SOURCES) headers/*.h $(TESTS_SOURCES) *.cpp	*.h view/*.cpp view/*.h
