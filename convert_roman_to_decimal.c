#include <string.h>

typedef struct 
{
	int character;
	int value;
	int order;
} roman_value_order;

roman_value_order I={'I',1,1};
roman_value_order V={'V',5,2};

int convert(char roman_text[])
{
	int result = 0;
	for(int i = 0; roman_text[i] != '\0'; i++) {
    	if (I.character == roman_text[i])
    	{
    		result = result+I.value;
    	}
    	else
    	{
    		result = result+V.value;
    	}
    }
	return result;
}