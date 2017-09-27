void	my_swap(int *a, int *b)
{
	int c;
	int d;
	c = (*a);
	d = (*b);
	(*a) = d;
	(*b) = c;
}
