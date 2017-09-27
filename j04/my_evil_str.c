int	my_strlen(char const *str)
{
	int i;
	i = 0;
	while(str[i] != '\0' && i < 2147483647)
		i++;
	return i;
}

char	*my_evil_str(char *str)
{
	int	i;
	int	k;
	char	c;
	int	size;

	size = my_strlen(str);
	k = 0;

	if((size%2))
	{
		//impair
		i = size-1;
                while(i > ((size/2)-1))
                {
                        c = str[i];
                        str[i] = str[k];
                        str[k] = c;
                        i--;
                        k++;
                }
			
	}
	else
	{
		//pair
		i = size-1;
		while(i > ((size/2)-1))
		{
			c = str[i];
			str[i] = str[k];
			str[k] = c;
			i--;
			k++;
		}
	}
	return str;

}
