#include "convert_roman_to_decimal.h"
#include "convert_decimal_to_roman.h"
#include "roman_calculator.h"
#include <stdlib.h>
#include <string.h>

int add_operation = 1;
int subtract_operation = 0;

void get_answer(return_type* return_value, char* first_roman_value, char* second_roman_value, int operation)
{
	int integer_result;
	if (operation == add_operation)
	{
		integer_result = convert_to_decimal(first_roman_value) + convert_to_decimal(second_roman_value);
	}
	else
	{
		integer_result = convert_to_decimal(first_roman_value) - convert_to_decimal(second_roman_value);
	}
	convert_to_roman(return_value->result_str, integer_result);

	if ((convert_to_decimal(first_roman_value) == -1) || (convert_to_decimal(second_roman_value) == -1) || ((integer_result > 3999) || (integer_result <= 0)))
	{
		return_value->error_code = 1;
		strcpy(return_value->result_str, "INVALID");
	}	

}

void add(return_type* return_value, char* first_roman_value, char* second_roman_value)
{
	get_answer(return_value, first_roman_value, second_roman_value, add_operation);
}

void subtract(return_type* return_value, char* first_roman_value, char* second_roman_value)
{
	get_answer(return_value, first_roman_value, second_roman_value, subtract_operation);	
}
