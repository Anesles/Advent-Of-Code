#include "../libft/libft.h"

char	find_common(char *h1, char *h2, char *h3)
{
	int	i,j,z;

	i = 0;
	while (h1[i])
	{
		j = 0;
		while (h2[j])
		{
			z = 0;
			while (h3[z])
			{
				if ((h1[i] == h2[j]) && (h2[j]== h3[z]))
					return (h1[i]);
				z++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_points(char c)
{
	int		i;
	char	*base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	main()
{
	int		points,fd;
	char	*h1, *h2, *h3, c;

	fd = open("input.txt", O_RDONLY);
	points = 0;
	h1 = ft_strtrim(get_next_line(fd), "\n");
	while (1)
	{
		if (!h1 || !h2 || !h3)
			break ;
		h2 = ft_strtrim(get_next_line(fd), "\n");
		h3 = ft_strtrim(get_next_line(fd), "\n");
		c = find_common(h1,h2,h3);
		points += get_points(c);
		h1 = ft_strtrim(get_next_line(fd), "\n");
	}
	ft_printf("Result = %d\n", points);
}