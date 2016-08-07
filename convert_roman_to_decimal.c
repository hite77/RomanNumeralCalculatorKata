#include <string.h>
#include "convert_roman_to_decimal.h"

roman_value_order I={1,1};
roman_value_order V={5,2};
roman_value_order X={10,3};
roman_value_order L={50,4};
roman_value_order C={100,5};
roman_value_order D={500,6};

int convert(char roman_text[])
{
	int result = 0;
	for(int i = 0; roman_text[i] != '\0'; i++) {
    	roman_value_order current_value=find_value(roman_text[i]);
		roman_value_order next_value;

		if ((roman_text[i+1] == '\0') || (current_value.order >= (next_value=find_value(roman_text[i+1])).order))
		{
			result += current_value.value;
		}
		else
		{
			result += (next_value.value-current_value.value);
			i++;
		} 	
    }
	return result;
}

roman_value_order find_value(int value)
{
	switch(value) {
		case 'V' : return V; 
		case 'X' : return X;
		case 'L' : return L;
		case 'C' : return C;
		case 'D' : return D;
		default: return I;
	}
}