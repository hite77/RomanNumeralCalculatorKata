int position = 0;
int ROMAN_M_1000 = 1000;
int ROMAN_C_100 = 100;
int ROMAN_X_10 = 10;

void convert_decimal_place(char* result, int value, int lowest_value, int mid_value, int high_value)
{
	switch (value) {
		case 1: result[position++]=lowest_value; break;
		case 2: result[position++]=lowest_value;result[position++]=lowest_value; break;
		case 3: result[position++]=lowest_value;result[position++]=lowest_value;result[position++]=lowest_value; break;
		case 4: result[position++]=lowest_value;result[position++]=mid_value; break;
		case 5: result[position++]=mid_value; break;
		case 6: result[position++]=mid_value;result[position++]=lowest_value; break;
		case 7: result[position++]=mid_value;result[position++]=lowest_value;result[position++]=lowest_value; break;
		case 8: result[position++]=mid_value;result[position++]=lowest_value;result[position++]=lowest_value;result[position++]=lowest_value; break;
		case 9: result[position++]=lowest_value;result[position++]=high_value; break;
	}
}

void convert_to_roman(char* result, int decimal)
{    
	while (decimal >= ROMAN_M_1000)
	{
		result[position++]='M';
		decimal -= ROMAN_M_1000;
	}
	
	int hundreds = decimal / ROMAN_C_100;
    convert_decimal_place(result, hundreds,'C','D','M');
    
    decimal = decimal - hundreds * ROMAN_C_100;
    int tens = decimal / ROMAN_X_10;
    
    convert_decimal_place(result, tens,'X','L','C');

    decimal = decimal - tens * ROMAN_X_10;
    int ones = decimal;

    convert_decimal_place(result, ones,'I','V','X');

	result[position] = '\0';
}