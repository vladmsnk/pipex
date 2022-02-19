#include "pipex_bonus.h"

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