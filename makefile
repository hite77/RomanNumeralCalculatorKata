CC      = gcc
CFLAGS=-Wall
LIBS=-lcheck

default: test

##all: sum2ints

##sum2ints: main.o implementation.o
##	$(CC) -o sum2ints main.o implementation.o

##main.o: main.c implementation.h
##	$(CC) $(CFLAGS) -c main.c

##implementation.o: implementation.c implementation.h
##	$(CC) $(CFLAGS) -c implementation.c

convert_roman_to_decimal.o: convert_roman_to_decimal.c convert_roman_to_decimal.h
	$(CC) $(CFLAGS) -c convert_roman_to_decimal.c

convert_decimal_to_roman.o: convert_decimal_to_roman.c convert_decimal_to_roman.h
	$(CC) $(CFLAGS) -c convert_decimal_to_roman.c

roman_calculator.o: roman_calculator.c roman_calculator.h
	$(CC) $(CFLAGS) -c roman_calculator.c

test: test_convert_from_roman_numeral_to_decimal test_convert_from_decimal_to_roman test_roman_calculator
	./test_convert_from_roman_numeral_to_decimal
	./test_convert_from_decimal_to_roman
	./test_roman_calculator

test_roman_calculator: test_roman_calculator.o roman_calculator.o
	$(CC) -o test_roman_calculator roman_calculator.o test_roman_calculator.o convert_roman_to_decimal.o convert_decimal_to_roman.o $(LIBS)

test_roman_calculator.o: test_roman_calculator.c roman_calculator.h
	$(CC) $(CFLAGS) -c test_roman_calculator.c

test_convert_from_decimal_to_roman: test_convert_from_decimal_to_roman.o convert_decimal_to_roman.o
	$(CC) -o test_convert_from_decimal_to_roman convert_decimal_to_roman.o  test_convert_from_decimal_to_roman.o $(LIBS)

test_convert_from_decimal_to_roman.o: test_convert_from_decimal_to_roman.c convert_decimal_to_roman.h
	$(CC) $(CFLAGS) -c test_convert_from_decimal_to_roman.c

test_convert_from_roman_numeral_to_decimal: test_convert_from_roman_numeral_to_decimal.o convert_roman_to_decimal.o
	$(CC) -o test_convert_from_roman_numeral_to_decimal convert_roman_to_decimal.o test_convert_from_roman_numeral_to_decimal.o $(LIBS)

test_convert_from_roman_numeral_to_decimal.o: test_convert_from_roman_numeral_to_decimal.c convert_roman_to_decimal.h
	$(CC) $(CFLAGS) -c test_convert_from_roman_numeral_to_decimal.c