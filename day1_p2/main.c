#include "stdio.h"
#include "stdlib.h"
#include "../libft/libft.h"

int	get_elfs(int fd)
{
	char	*line;
	int		n;

	n = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_isdigit(line[0]))
			n += 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (n);
}

int	get_cals(int fd)
{
	char	*line;
	int		sum;

	line = get_next_line(fd);
	sum = 0;
	while(ft_isdigit(line[0]))
	{
		line = ft_strtrim(line, "\n\t\e\r\v\f");
		sum += ft_atoi(line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break;
	}
	free(line);
	return (sum);
}

void	sort(int *max, int	max_elfs)
{
	int	i;
	int	j;
	int	min;
	int	temp;

	i = 0;
	j = 0;
	while (i < max_elfs)
	{
		j = i + 1;
		min = i;
		while (j < max_elfs)
		{
			if (max[j] < max[min])
				min = j;
			j++;
		}
		temp = max[min];
		max[min] = max[i];
		max[i] = temp;
		i++;
	}
	ft_printf("Sum of max 3 = %d calories.\n", (max[max_elfs - 1] + max[max_elfs - 2] + max[max_elfs - 3]));
}

int	main(void)
{
	int	*max;
	int	fd;
	int	i;
	int	n_elfs;

	fd = open("input.txt", O_RDWR);
	if (!fd)
		return (0);
	n_elfs = get_elfs(fd);
	max = (int *)malloc(n_elfs * sizeof(int));
	close(fd);
	fd = open("input.txt", O_RDWR);
	i = 0;
	while (i < n_elfs)
		max[i++] = get_cals(fd);
	sort(max, n_elfs);
	free(max);
	close(fd);
}