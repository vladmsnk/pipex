#include "pipex.h"
#include <errno.h>
#include <get_next_line.h>

void	get_error()
{
	perror("Error !\n");
	exit(1);
}


void	execute_command(char *cmd, char **envp)
{
	char	**splited_path;
	char	**splited_cmd;
	char	*cur_cmd;
	char	*path;
	int		i;

	path = extract_paths(envp);
	splited_path = ft_split(path, ':');
	splited_cmd = ft_split(cmd, ' ');
	if (access(splited_cmd[0], X_OK) == 0)
			execve(splited_cmd[0], splited_cmd, envp);
	i = 0;
	while (splited_path[i])
	{
		cur_cmd = ft_strjoin(splited_path[i++], "/");
		cur_cmd = ft_strjoin(cur_cmd, splited_cmd[0]);
		if (access(cur_cmd, X_OK) == 0)
		{
			execve(cur_cmd, splited_cmd, envp);
		}
	}
	perror("command not found");
	exit(EXIT_FAILURE);
}

void	exec_first_command(int *fds, int fd1, char *cmd, char **envp)
{
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	execute_command(cmd, envp);
	close(fds[1]);
}

void	exec_second_command(int *fds, int fd2, char *cmd, char **envp)
{
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	execute_command(cmd, envp);
	close(fds[0]);
}

void	check_normal_exit(int wstatus)
{
	int	status_code;

	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		if (status_code != 0)
		{
			exit(EXIT_SUCCESS);
		}
	}
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		fds[2];
	int		pid[2];
	int		wstatus;
	int		i;

	if (pipe(fds) == -1)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (i == 0)
				exec_first_command(fds, fd1, argv[2], envp);
			else if (i == 1)
				exec_second_command(fds, fd2, argv[3], envp);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	i = 0;
	waitpid(pid[0], NULL, 1);
	waitpid(pid[1], NULL, 1);
	// while (i < 2)
	// {
	// 	waitpid(pid[i], NULL, 0);
	// 	i++;
	// }
	// pid1 = fork();
	// if (pid1 == -1)
	// 	get_error();
	// if (pid1 == 0)
	// {
	// 	exec_first_command(fds, fd1, argv[2], envp);
	// 	exit(EXIT_SUCCESS);
	// }
	// pid2 = fork();
	// if (pid2 == -1)
	// 	get_error();
	// if (pid2 == 0)
	// {
	// 	exec_second_command(fds, fd2, argv[3], envp);
	// 	exit(EXIT_SUCCESS);
	// }
}


void	pipex_bonus(char **argv, char **envp, int argc)
{
	int	cmp;	
	int	*pids; // to struct
	int	**fds; // to struct
	int	num_of_cmds;

	num_of_cmds = argc - 3;
	pids = (int *)malloc(sizeof(int) * (argc - 3)); 
	if (!pids)
		exit(EXIT_FAILURE);
	fds = open_pipes(num_of_cmds - 1);
	cmp = 0;
	while (cmp < num_of_cmds)
	{
		pids[cmp] = fork();
		if (pids[cmp] == 0)
		{
			if (cmp == 0)
				redirect_infile(argv[1], fds[0]);
			else if (cmp == num_of_cmds - 1)
				redirect_outfile(argv[argc - 1], fds[cmp - 1]);
			else
				manage_pipes(cmp, fds, num_of_cmds - 1);
			close_pipes(fds, num_of_cmds - 1);
			execute_command(argv[cmp + 2], envp);
		}
		else if (pids[cmp] < 0)
			exit(EXIT_FAILURE);
		cmp++;
	}
	wait_all_childs(pids, num_of_cmds);
}

// void	execute_first_part(char **argv, char **envp, int argc, int *fds1, int *fds2)
// {
// 	char *line;

// 	close(fds1[1]);
// 	while (1)
// 	{
// 		line = get_next_line(1);
// 		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
// 			break;
// 		write(fds1[1], line, ft_strlen(line));
// 	}
// 	dup2(fds1[0], STDIN_FILENO);
// 	dup2(fds2[1], STDOUT_FILENO);
// 	close(fds2[0]);
// 	execute_command(argv[3], envp);
// }

// void	pipex_here_doc(char **argv, char **envp, int argc)
// {
// 	char *line;
// 	int	pid1;
// 	int	pid2;
// 	int	fds1[2];
// 	int	fds2[2];

// 	if (pipe(fds1) == -1)
// 		exit(EXIT_FAILURE);
// 	if (pipe(fds2) == -1)
// 		exit(EXIT_FAILURE);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 		execute_first_part(argv, envp, argc, fds1, fds2);
// 	pid2 = fork();
// 	if (pid2 == 0)
// 		execute_second_command(...);
// }

int main(int argc, char **argv, char **envp)
{
	int	fd1;
    int	fd2;
	int	wstatus;

	if (envp && argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0 && argc == 6)
			pipex_here_doc(argv, envp, argc);
		else
			pipex_bonus(argv, envp, argc);
	}
	else
		get_error();
    return (0);
}