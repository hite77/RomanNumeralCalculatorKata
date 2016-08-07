#ifndef CONVERT_ROMAN_TO_DECIMAL_H
#define CONVERT_ROMAN_TO_DECIMAL_H

typedef struct roman_value_orders
{
	int character;
	int value;
	int order;
} roman_value_order;

int convert(char * roman_text);
roman_value_order find_value(int value);

#endif /* CONVERT_ROMAN_TO_DECIMAL_H*/
