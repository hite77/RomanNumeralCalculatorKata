#include <string.h>
#include <stdlib.h>
#include "convert_roman_to_decimal.h"

typedef struct roman_value_orders
{
	int value;
	int order;
} roman_value_order;

int max_multiplier = 10;
int max_roman_integer = 3999;

roman_value_order I={1,1};
roman_value_order V={5,2};
roman_value_order X={10,3};
roman_value_order L={50,4};
roman_value_order C={100,5};
roman_value_order D={500,6};
roman_value_order M={1000,7};

roman_value_order find_value(int value)
{
	switch(value) {
		case 'V' : return V; 
		case 'X' : return X;
		case 'L' : return L;
		case 'C' : return C;
		case 'D' : return D;
		case 'M' : return M;
		default: return I;
	}
}

void exit_on_illegal_duplicate_values(char roman_text[])
{
	if(strstr(roman_text, "VV") || strstr(roman_text, "DD") || strstr(roman_text, "LL"))
	{
		exit(3);
	}
}

int convert_to_decimal(char roman_text[])
{
	int result = 0;
	exit_on_illegal_duplicate_values(roman_text);
	for(int i = 0; roman_text[i] != '\0'; i++) {
    	roman_value_order current_value=find_value(roman_text[i]);
		roman_value_order next_value;

		if ((roman_text[i+1] == '\0') || (current_value.order >= (next_value=find_value(roman_text[i+1])).order))
		{
			result += current_value.value;
		}
		else if (next_value.value / current_value.value <= max_multiplier)
		{
			result += (next_value.value-current_value.value);
			i++;
		} 	
		else
		{
			return -1;
		}
		if (result > max_roman_integer)
		{
			exit(2);
		}
    }
	return result;
}

