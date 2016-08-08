void convert_to_roman(int decimal, char* result)
{
	int position = 0;
        
	while (decimal >= 1000)
	{
		result[position++]='M';
		decimal -= 1000;
	}
	
	if (decimal > 0)
	{
		result[position++]='C';
	}

	result[position] = '\0';
}

