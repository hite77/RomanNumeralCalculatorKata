void convert_to_roman(int decimal, char* result)
{
	int position = 0;
        
	while (decimal >= 1000)
	{
		result[position++]='M';
		decimal -= 1000;
	}
	
	int hundreds = decimal / 100;
	switch (hundreds) {
		case 1: result[position++]='C'; break;
		case 2: result[position++]='C';result[position++]='C'; break;
		case 3: result[position++]='C';result[position++]='C';result[position++]='C'; break;
	}

	result[position] = '\0';
}

