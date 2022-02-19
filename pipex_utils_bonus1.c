#include "pipex_bonus.h"

void	clean_double(int **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}

int	**open_pipes(int pipes_num)
{
	int	i;
	int **fds;

	i = 0;
	fds = (int **)malloc(sizeof(int *) * pipes_num);
	if (!fds)
		return (NULL);
	while (i < pipes_num)
	{
		fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!fds[i] || pipe(fds[i]) == -1)
		{
			clean_double(fds, i + 1);
			return (NULL);
		}
		i++;
	}
	return (fds);
}

t_init	*allocate_memory(int proc_num)
{
	t_init	*cur;

	cur = (t_init *)malloc(sizeof(t_init));
	if (!cur)
		return (NULL);
	cur->fds = open_pipes(proc_num - 1);
	if (!(cur->fds))
	{
		free (cur);
		return (NULL);
	}
	cur->pids = (int *)malloc(sizeof(int) * proc_num);
	if (!(cur->pids))
	{
		clean_double(cur->fds, proc_num - 1);
		free(cur);
		return (NULL);
	}
}