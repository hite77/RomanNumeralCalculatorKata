void convert_to_roman(int decimal, char* result)
{
	int position = 0;
        
	while (decimal >= 1000)
	{
		result[position++]='M';
		decimal -= 1000;
	}
	
	int hundreds = decimal / 100;

	if (hundreds==1)
	{
		result[position++]='C';
	}
	else if (hundreds==2)
	{
		result[position++]='C';
		result[position++]='C';
	}

	result[position] = '\0';
}

