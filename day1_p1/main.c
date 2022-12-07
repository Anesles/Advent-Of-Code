#include "stdio.h"
#include "stdlib.h"
#include "../libft/libft.h"


int	main(void)
{
	char	*line;
	int		fd;
	int		sum;
	int		max[2];
	int		n;

	fd = open("input.txt", O_RDWR);
	if (!fd)
		return (0);
	n = 1;
	sum = 0;
	max[0] = 0;
	max[1] = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = ft_strtrim(line, "\n");
		if (!ft_isdigit(line[0]))
		{
			if (max[0] < sum)
			{
				max[0] = sum;
				max[1] = n;
			}
			sum = 0;
			n += 1;
		}
		else
			sum += ft_atoi(line);
		line = get_next_line(fd);
	}
	ft_printf("Max calories carried is %d calories by Elf %d\n", max[0], max[1]);
}