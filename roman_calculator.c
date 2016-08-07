#include "convert_roman_to_decimal.h"
#include "convert_decimal_to_roman.h"

void add(char* first_roman_value, char* second_roman_value, char* result)
{
	convert_to_roman(convert_to_decimal(first_roman_value)+convert_to_decimal(second_roman_value), result);
}

void subtract(char* first_roman_value, char* second_roman_value, char* result)
{
	convert_to_roman(convert_to_decimal(first_roman_value)-convert_to_decimal(second_roman_value), result);
}
