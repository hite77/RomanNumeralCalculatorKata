CC      = gcc
CFLAGS=-Wall -std=c99
LDFLAGS= -pthread -lpthread -lm -lrt
LIBS=-lcheck
PWD	= `PWD`

default: test

docker:
	docker build -t romancalculatordocker:latest .
	docker run -it -v $(PWD):/usr/roman romancalculatordocker

clean:
	rm -f *.o test_convert_from_roman_numeral_to_decimal test_convert_from_decimal_to_roman test_roman_calculator

convert_roman_to_decimal.o: convert_roman_to_decimal.c convert_roman_to_decimal.h return_value_and_error_code.h
	$(CC) $(CFLAGS) -c convert_roman_to_decimal.c

convert_decimal_to_roman.o: convert_decimal_to_roman.c convert_decimal_to_roman.h return_value_and_error_code.h
	$(CC) $(CFLAGS) -c convert_decimal_to_roman.c

roman_calculator.o: roman_calculator.c roman_calculator.h return_value_and_error_code.h
	$(CC) $(CFLAGS) -c roman_calculator.c

test: clean test_convert_from_roman_numeral_to_decimal test_convert_from_decimal_to_roman test_roman_calculator
	./test_convert_from_roman_numeral_to_decimal
	./test_convert_from_decimal_to_roman
	./test_roman_calculator

test_roman_calculator: test_roman_calculator.o roman_calculator.o
	$(CC) -o test_roman_calculator roman_calculator.o test_roman_calculator.o convert_roman_to_decimal.o convert_decimal_to_roman.o $(LIBS) $(LDFLAGS)

test_roman_calculator.o: test_roman_calculator.c roman_calculator.h return_value_and_error_code.h
	$(CC) $(CFLAGS) -c test_roman_calculator.c

test_convert_from_decimal_to_roman: test_convert_from_decimal_to_roman.o convert_decimal_to_roman.o
	$(CC) -o test_convert_from_decimal_to_roman convert_decimal_to_roman.o  test_convert_from_decimal_to_roman.o $(LIBS) $(LDFLAGS)

test_convert_from_decimal_to_roman.o: test_convert_from_decimal_to_roman.c convert_decimal_to_roman.h return_value_and_error_code.h
	$(CC) $(CFLAGS) -c test_convert_from_decimal_to_roman.c

test_convert_from_roman_numeral_to_decimal: test_convert_from_roman_numeral_to_decimal.o convert_roman_to_decimal.o
	$(CC) -o test_convert_from_roman_numeral_to_decimal convert_roman_to_decimal.o test_convert_from_roman_numeral_to_decimal.o $(LIBS) $(LDFLAGS)

test_convert_from_roman_numeral_to_decimal.o: test_convert_from_roman_numeral_to_decimal.c convert_roman_to_decimal.h return_value_and_error_code.h
	$(CC) $(CFLAGS) -c test_convert_from_roman_numeral_to_decimal.c
