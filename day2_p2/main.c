#include "../libft/libft.h"

/*
A = X = Rock	= 1 Points
B = Y = Paper	= 2 Points
C = Z = Scissors= 3 Points

Win	= 6 Points
Draw= 3 Points
Lose= 0 Points
*/

int	main(void)
{
	int		fd;
	char	*line;
	int		points;

	fd = open("input.txt", O_RDWR);
	line = get_next_line(fd);
	points = 0;
	while(line)
	{
		line = ft_strtrim(line, "\n");
		if (line[0] == 'A')
		{
			if (line[2] == 'X')
				points += (3 + 0);
			else if (line[2] == 'Y')
				points += (1 + 3);
			else if (line[2] == 'Z')
				points += (2 + 6);
			
		}
		else if (line[0] == 'B')
		{
			if (line[2] == 'X')
				points += (1 + 0);
			else if (line[2] == 'Y')
				points += (2 + 3);
			else if (line[2] == 'Z')
				points += (3 + 6);
		}
		else if (line[0] == 'C')
		{
			if (line[2] == 'X')
				points += (2 + 0);
			else if (line[2] == 'Y')
				points += (3 + 3);
			else if (line[2] == 'Z')
				points += (1 + 6);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	ft_printf("Total points = %d\n", points);
	close(fd);
	return (0);
}
