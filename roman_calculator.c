#include "convert_roman_to_decimal.h"
#include "convert_decimal_to_roman.h"
#include <stdlib.h>

void add(char * result, char* first_roman_value, char* second_roman_value)
{
	int integer_result_of_add = convert_to_decimal(first_roman_value)+convert_to_decimal(second_roman_value);
	if (integer_result_of_add > 3999)
	{
		exit(2);
	}
	convert_to_roman(result, integer_result_of_add);
}

void subtract(char* result, char* first_roman_value, char* second_roman_value)
{
	int integer_result_of_subtract = convert_to_decimal(first_roman_value)-convert_to_decimal(second_roman_value);
	if (integer_result_of_subtract <= 0)
	{
		exit(4);
	}
	convert_to_roman(result, convert_to_decimal(first_roman_value)-convert_to_decimal(second_roman_value));
}
