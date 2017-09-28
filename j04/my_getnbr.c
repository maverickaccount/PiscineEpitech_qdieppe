int	my_ciflen(char const *str)
{
	int i;
	i = 0;
	while(str[i] != '\0' && i < 2147483647 && str[i] > 0x2f && str[i] < 0x3a)
		i++;
	return i;
}

char	bypass(char const *str, int *begin)
{
	int	i;
	int	neg_count;
	i = 0;
	neg_count = 0;

	while(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			neg_count++;
		i++;
	}
	(*begin) = i;
	if((neg_count%2))
		return ('-'); //impair
	else
		return ('+'); //pair
}

int	isnum(char a)
{
	if(a < 0x30 || a > 0x39)
		return 0;
	else
		return 1;
}

int	verify_for_max(const char *str, const char *my_str)
{
	int	i;
	i = 	0;

	while(i < 10)
	{
		if(my_str[i] < str[i])
			return 1;
		i++;
	}
	return 0;
}

int     isequal(const char *str, const char *my_str)
{
        int     i;
        i = 0;

        while(i < 10)
        {
		if(str[i] != my_str[i])
			return 0;
        }
        return 1;
}

int	my_getnbr(char const *str)
{
	int		i;
	int		size;
	int		number;
	char		isneg;
	
	isneg = bypass(str,&i);
	size = my_ciflen(str + i);
	number = 0;
	
	if(size < 10)
	{
		while(i < (size + i) && isnum(str[i]))
		{
			number += str[i] - 0x30;
			if(i < (size -1 + i) && isnum(str[i + 1]))
				number *= 10;
        	        i++;
		}
	}
	else if(size == 10)
	{
		if(isneg == '-')
		{
			if(verify_for_max("2147483648", (char *) str))
			{
				while(i < (size + i) && isnum(str[i]))
                		{
        			        number += str[i] - 0x30;
	                        	if(i < (size -1 + i) && isnum(str[i + 1]))
                                		number *= 10;
                        		i++;
                		}

			}
			if(isequal("2147483648", str))
					return -2147483648;
		}
		else
		{
			if(verify_for_max("2147483648",  str))
			{
				while(i < (size + i) && isnum(str[i]))
                                {       
                                        number += str[i] - 0x30;
                                        if(i < (size -1 + i) && isnum(str[i + 1]))
                                                number *= 10;
                                        i++;
                                }       

			}
		}
	}
	else
		return 0;

	if(isneg == '-')
	{
		return (int) -(number);
	}
	else
	{
		return (int) (number);
	}
}

int	main(int argc, char **argv)
{
	int k;
	k = my_getnbr(argv[1]);
	printf("%d\n", k);
	return 0;
}
