#include "pipex.h"

t_init	*allocate_memory(void)
{
	t_init *cur;

	cur = (t_init *)malloc(sizeof(t_init));
	if (!cur)
		return (NULL);
	cur->fds = (int *)malloc(sizeof(int) * 2);
	if (!(cur->fds))
	{
		free(cur);
		return (NULL);
	}
	cur->pids = (int *)malloc(sizeof(int) * 2);
	if (!(cur->pids))
	{
		free(cur->fds);
		free(cur);
		return (NULL);
	}
}

void	clean_variables(t_init *tmp, int exit_stat)
{
	free(tmp->fds);
	free(tmp->pids);
	free(tmp);
	exit(exit_stat);
}


void	redirect_infile(char *infile, int *fds_init)
{
	int	fd1;

	fd1 = open(infile, O_RDWR, 0777);
	if (fd1 == -1)
		exit(EXIT_FAILURE);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	dup2(fds_init[1], STDOUT_FILENO);
}

void	redirect_outfile(char *outfile, int *fds_end)
{
	int	fd2;

	fd2 = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
		exit(EXIT_FAILURE);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	dup2(fds_end[0], STDIN_FILENO);
}

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
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (fds);
}

void	close_pipes(int **fds, int pipe_cnt)
{
	int	i;

	i = 0;
	while (i < pipe_cnt)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		i++;
	}
}

void	manage_pipes(int curr_pipe, int **fds, int pipes_num)
{
	int	i;

	i = 0;
	dup2(fds[curr_pipe - 1][0], STDIN_FILENO);
	dup2(fds[curr_pipe][1], STDOUT_FILENO);
}

void	wait_all_childs(int *pids, int num_of_forks)
{
	int	i;

	i = 0;
	while (i < num_of_forks)
		waitpid(pids[i++], NULL, 1);
}
