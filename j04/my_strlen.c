int	my_strlen(char const *str)
{
	int i;
	i = 0;
	while(str[i] != '\0' && i < 2147483647)
		i++;
	return i;
}
