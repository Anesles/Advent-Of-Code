#include "../libft/libft.h"

int	check_contains(char *h1, char *h2)
{
	int	t1, t2, l1, l2;

	t1 = ft_atoi(ft_substr(h1, 0, ft_strchrr(h1, '-')));
	t2 = ft_atoi(ft_substr(h1, ft_strchrr(h1, '-') + 1, ft_strlen(h1) - ft_strchrr(h1, '-') - 1));
	ft_printf("H1 = %s;\nN1 = %d; N2 = %d;\n", h1, t1, t2);
	l1 = ft_atoi(ft_substr(h2, 0, ft_strchrr(h2, '-')));
	l2 = ft_atoi(ft_substr(h2, ft_strchrr(h2, '-') + 1, ft_strlen(h2) - ft_strchrr(h2, '-') - 1));
	ft_printf("H2 = %s;\nN1 = %d; N2 = %d;\n", h2, l1, l2);
	if (l1 >= t1 && l1 <= t2)
	{
		ft_printf("H2 overlaps H1\n\n");
		return (1);
	}
	else if (t1 >= l1 && t1 <= l2)
	{
		ft_printf("H1 overlaps H2\n\n");
		return (1);
	}
	if (l2 <= t2 && l2 >= t1)
	{
		ft_printf("H2 overlaps H1\n\n");
		return (1);
	}
	else if (t2 <= l2 && t2 >= l1)
	{
		ft_printf("H1 overlaps H2\n\n");
		return (1);
	}
	return (0);
}

int	main()
{
	char	*line, *h1, *h2;
	int		fd, points;

	fd = open("input.txt", O_RDONLY);
	line = ft_strtrim(get_next_line(fd), "\n");
	points = 0;
	while (1)
	{
		if (!line)
			break ;
		h1 = ft_substr(line, 0, ft_strchrr(line, ','));
		h2 = ft_substr(line, ft_strchrr(line, ',') + 1, ft_strlen(line) - ft_strchrr(line, ',') - 1);
		ft_printf("Line = %s;\n", line);
		points += check_contains(h1, h2);
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	free(line);
	ft_printf("%d ranges that contains the other\n", points);
	close(fd);
}