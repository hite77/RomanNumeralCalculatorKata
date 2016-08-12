#include "convert_roman_to_decimal.h"
#include "convert_decimal_to_roman.h"
#include "roman_calculator.h"
#include <stdlib.h>
#include <string.h>

void add(return_type* return_value, char* first_roman_value, char* second_roman_value)
{
	int integer_result_of_add = convert_to_decimal(first_roman_value)+convert_to_decimal(second_roman_value);
	if (integer_result_of_add > 3999)
	{
		exit(2);
	}
	convert_to_roman(return_value->result_str, integer_result_of_add);

	if ((convert_to_decimal(first_roman_value) == -1) || (convert_to_decimal(second_roman_value) == -1))
	{
		return_value->error_code = 1;
		strcpy(return_value->result_str, "INVALID");
	}	
}

void subtract(return_type* return_value, char* first_roman_value, char* second_roman_value)
{
	int integer_result_of_subtract = convert_to_decimal(first_roman_value)-convert_to_decimal(second_roman_value);
	if ((convert_to_decimal(first_roman_value) == -1) || (convert_to_decimal(second_roman_value) == -1) || (integer_result_of_subtract <= 0))
	{
		return_value->error_code = 1;
		strcpy(return_value->result_str, "INVALID");
	}	
	else
	{
		convert_to_roman(return_value->result_str, convert_to_decimal(first_roman_value)-convert_to_decimal(second_roman_value));
	}
}
