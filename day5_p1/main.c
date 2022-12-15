#include "../libft/libft.h"

int	get_containers(char	*line)
{
	int	i, count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			count++;
		else if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (count);
}

int	main()
{
	char	*line;
	int		fd, lines, cols;

	fd = open("input.txt", O_RDONLY);
	line = get_next_line(fd);
	lines = 0;
	cols = 0;
	while (1)
	{
		if (line[0] == '\n')
			break ;
		cols = get_containers(line);
		if (cols == 0)
			lines++;
		line = get_next_line(fd);
	}
	ft_printf("Lines = %d; Collumns = %d\n", lines, cols);
	close(fd);
}