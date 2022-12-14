#include "../libft/libft.h"

char	find_common(char *h1, char *h2)
{
	int	i,j;

	i = 0;
	while (h1[i])
	{
		j = 0;
		while (h2[j])
		{
			if (h1[i] == h2[j])
				return (h1[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_points(char c)
{
	int	i;
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
	char	*line, *h1, *h2, c;

	fd = open("input.txt", O_RDONLY);
	points = 0;
	line = ft_strtrim(get_next_line(fd), "\n");
	while (1)
	{
		if (!line)
			break;
		h1 = ft_substr(line, 0, ft_strlen(line) / 2);
		h2 = ft_substr(line, ft_strlen(line) / 2, ft_strlen(line) / 2);
		c = find_common(h1, h2);
		points += get_points(c);
		ft_printf("Line = %s;\nH1 = %s; H2 = %s;\nPoints('%c') = %d\n\n", line, h1, h2, c, get_points(c));
		free(h1);
		free(h2);
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	free(line);
	close(fd);
	ft_printf("Result = %d\n", points);
}