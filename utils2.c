
int count_collectibles(char **map)
{
	int	i;
	int	j;
	int c;

	if (!map)
    	return (0);
	i = 0;
	c = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				c++;
			++j;
		}
		++i;
	}
	return (c);
}
