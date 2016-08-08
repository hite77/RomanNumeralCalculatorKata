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
		case 4: result[position++]='C';result[position++]='D'; break;
		case 5: result[position++]='D'; break;
		case 6: result[position++]='D';result[position++]='C'; break;
		case 7: result[position++]='D';result[position++]='C';result[position++]='C'; break;
		case 8: result[position++]='D';result[position++]='C';result[position++]='C';result[position++]='C'; break;
		case 9: result[position++]='C';result[position++]='M'; break;
	}

	result[position] = '\0';
}

