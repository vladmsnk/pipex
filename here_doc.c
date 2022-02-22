#include "pipex_bonus.h"

int	*get_input(int *fds1, char **argv)
{
	char	*line;

	fds1 = (int *)malloc(sizeof(int) * 2);
	if (!fds1)
		exit(EXIT_FAILURE);
	if (pipe(fds1) == -1)
		exit(EXIT_FAILURE);
	dup2(fds1[1], STDOUT_FILENO);
	close(fds1[1]);
	line = get_next_line(0);
	while (line && ft_strncmp(line, argv[2], ft_strlen(argv[2])) != 0)
	{
		write(STDOUT_FILENO, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	return (fds1);
}

void	handle_first(int *fds1,int *fds2, char **argv, char **envp)
{
	dup2(fds1[0], STDIN_FILENO);
	close(fds1[1]);
	close(fds1[0]);
	dup2(fds2[1], STDOUT_FILENO);
	close(fds2[0]);
	close(fds2[1]);
	execute_command(argv[3], envp);
}

void	handle_second(int *fds1, int *fds2, char **argv, char **envp)
{
	int fd;

	dup2(fds2[0], STDIN_FILENO);
	close(fds1[1]);
	close(fds1[0]);
	close(fds2[0]);
	close(fds2[1]);
	fd = open(argv[5], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execute_command(argv[4], envp);
}

void	here_doc_exec(char **argv, char **envp)
{
	int	*fds1;
	int	pid1;
	int pid2;
	int	*fds2;
	int stat;

	fds1 = get_input(fds1, argv);
	fds2 = (int *)malloc(sizeof(int) * 2);
	if (!fds2)
		exit(EXIT_FAILURE);
	if (pipe(fds2) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == 0)
		handle_first(fds1, fds2, argv, envp);
	pid2 = fork();
	if (pid2 == 0)
		handle_second(fds1, fds2, argv, envp);
	// close(fds2[1]);
	// close(fds2[0]);
	// close(fds1[1]);
	// close(fds1[0]);
	// waitpid(pid1,NULL,0);
	// waitpid(pid2,NULL,0);
}