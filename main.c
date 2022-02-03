#include "pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0 && s)
	{
		while (*s != '\0')
			ft_putchar_fd(*s++, fd);
	}
}

// void	exec_first_command(int *fds, int fd1, char **argv, char *paths)
// {
// 	return ;
// }

// void	exec_second_command(int *fds, int fd2, char **argv, char *paths)
// {
// 	return ;
// }
void	clean_dbl_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	help_print(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	
}

int	execute_command(char *cmd, char *paths)
{
	char	**spltd_path;
	char	**spltd_cmd;
	int		i;

	i = 0;
	spltd_path = ft_split(paths, ':');
	spltd_cmd = ft_split(cmd, ' ');

	while (spltd_path[i])
	{

	}
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

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		fds[2];
	int		pid1;
	int		pid2;
	char	*paths;

	if (pipe(fds) == -1)
		exit(3);
	paths = extract_paths(envp);
	// pid1 = fork();
	// if (pid1 == 0)
	// 	exec_first_command(fds, fd1, argv[2], paths);
	// pid2 = fork();
	// if (pid2 == 0)
	// 	exec_second_command(fds, fd2, argv[3], paths);
}

int main(int argc, char **argv, char **envp)
{
	int	fd1;
    int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[argc -1], O_WRONLY | O_CREAT); //maybe wrong
	if (fd1 == -1 || fd2 == -1)
		exit(2);
	pipex(fd1, fd2, argv, envp);
    return (0);
}