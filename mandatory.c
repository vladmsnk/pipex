#include "pipex_bonus.h"

void	handle_first_cmd(t_init *tmp, char **argv, char **envp)
{
	dup2(tmp->fd1, STDIN_FILENO);
	close(tmp->fd1);
	dup2(tmp->fds[0][1], STDOUT_FILENO);
	close(tmp->fds[0][1]);
	close(tmp->fds[0][0]);
	close(tmp->fd2);
	execute_command(argv[2], envp);
}

void	handle_second_cmd(t_init *tmp, char **argv, char **envp)
{
	dup2(tmp->fds[0][0], STDIN_FILENO);
	close(tmp->fds[0][1]);
	close(tmp->fds[0][0]);
	dup2(tmp->fd2, STDOUT_FILENO);
	close(tmp->fd2);
	close(tmp->fd1);
	execute_command(argv[3], envp);
}

void	pipex(int argc, char **argv, char **envp)
{
    t_init *tmp;

	tmp = allocate_memory(2);
    if (!tmp)
		exit(EXIT_FAILURE);
	tmp->fd1 = open(argv[1], O_RDWR, 0777);
	if (tmp->fd1 == -1)
		exit(EXIT_FAILURE);
	tmp->fd2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (tmp->fd2 == -1)
		exit(EXIT_FAILURE);
	tmp->pids[0] = fork();
    if (tmp->pids[0] == 0)
		handle_first_cmd(tmp, argv, envp);
    else if (tmp->pids[0] == -1)
		clean_variables(tmp, 1, EXIT_FAILURE);
	tmp->pids[1] = fork();
	if (tmp->pids[1] == 0)
		handle_second_cmd(tmp, argv, envp);
    else if (tmp->pids[1] == -1)
	clean_variables(tmp, 1, EXIT_FAILURE);
	else 
		close_pipes(tmp->fds, 1);
	wait_all_childs(tmp->pids, 2);
}

int	main(int argc, char **argv, char **envp)
{
	if (envp && argc == 5)
		pipex(argc, argv, envp);
	else
		exit(EXIT_FAILURE);
}