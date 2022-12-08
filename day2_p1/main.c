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
				points += 3 + 1;
			else if (line[2] == 'Y')
				points += 6 + 2;
			else if (line[2] == 'Z')
				points += 0 + 3;
			
		}
		else if (line[0] == 'B')
		{
			if (line[2] == 'X')
				points += 0 + 1;
			else if (line[2] == 'Y')
				points += 3 + 2;
			else if (line[2] == 'Z')
				points += 6 + 3;
		}
		else if (line[0] == 'C')
		{
			if (line[2] == 'X')
				points += 6 + 1;
			else if (line[2] == 'Y')
				points += 0 + 2;
			else if (line[2] == 'Z')
				points += 3 + 3;
		}
		line = get_next_line(fd);
	}
	ft_printf("Total points = %d\n", points);
	return (0);
}
