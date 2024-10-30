CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lcheck -lpthread -lrt -lm -lsubunit
EXECUTABLE = test

SOURCES = $(wildcard functions/*.c) 
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
SRC_TESTS = $(wildcard tests/*.c)
OBJ_TESTS = $(patsubst %.c, %.o, $(SRC_TESTS))

HEADERS = s21_matrix.h

all: $(EXECUTABLE) clean

s21_matrix.a: $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): s21_matrix.a $(OBJ_TESTS)
	$(CC) $(CFLAGS) $(OBJ_TESTS) s21_matrix.a $(LDFLAGS) -o $(EXECUTABLE)
	./$(EXECUTABLE)

gcov_report: s21_matrix.a
	$(CC) $(CFLAGS) --coverage $(SOURCES) s21_matrix.a tests/*.c $(LDFLAGS) -o gcov_report
	./gcov_report
	lcov -t "gcov_report" -o report.info --no-external -c -d .
	genhtml -o report/ report.info
	open report/index.html

clean:
	rm -rf s21_matrix.a
	rm -rf $(EXECUTABLE)
	rm -rf ./report
	rm -rf gcov_report
	rm -rf *.gcno *.gcda *.gcov *.info ./tests/*.log
	rm -rf $(OBJECTS) $(OBJ_TESTS)

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(EXECUTABLE)

clang:
	clang-format -n ./**/*.c ./**/*.h -style=Google
