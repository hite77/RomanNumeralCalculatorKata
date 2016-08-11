#include "convert_roman_to_decimal.h"
#include "convert_decimal_to_roman.h"

void add(char * result, char* first_roman_value, char* second_roman_value)
{
	convert_to_roman(result, convert_to_decimal(first_roman_value)+convert_to_decimal(second_roman_value));
}

void subtract(char* result, char* first_roman_value, char* second_roman_value)
{
	convert_to_roman(result, convert_to_decimal(first_roman_value)-convert_to_decimal(second_roman_value));
}
