int position = 0;

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

void convert_to_roman(int decimal, char* result)
{    
	while (decimal >= 1000)
	{
		result[position++]='M';
		decimal -= 1000;
	}
	
	int hundreds = decimal / 100;
    convert_decimal_place(result, hundreds,'C','D','M');
	result[position] = '\0';
}