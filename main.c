#include "pipex.h"

void	get_error()
{
	perror("Error !\n");
	exit(1);
}

char	*extract_paths(char **envp)
{
	char	*paths;
	int		i;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			paths = ft_strdup(envp[i] + 5);
		i++;
	}
	return (paths);
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
			execve(cur_cmd, splited_cmd, envp);
	}
	get_error();
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

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		fds[2];
	int		pid1;
	int		pid2;

	if (pipe(fds) == -1)
		exit(2);
	pid1 = fork();
	if (pid1 == -1)
		get_error();
	if (pid1 == 0)
		exec_first_command(fds, fd1, argv[2], envp);
	pid2 = fork();
	if (pid2 == -1)
		get_error();
	if (pid2 == 0)
		exec_second_command(fds, fd2, argv[3], envp);
}

void	pipex_bonus(int fd1, int fd2, char **argv, char **envp)
{

}
int main(int argc, char **argv, char **envp)
{
	int	fd1;
    int	fd2;
	if (envp && argc >= 5)
	{
		fd1 = open(argv[1], O_RDWR, 0777);
		fd2 = open(argv[argc -1], O_RDWR | O_CREAT | O_TRUNC, 0777); //maybe wrong
		if (fd1 == -1 || fd2 == -1)
			get_error();
		pipex(fd1, fd2, argv, envp);
		wait(NULL);
	} else
		get_error();
    return (0);
}