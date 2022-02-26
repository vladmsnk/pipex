#include "pipex_bonus.h"
#include <string.h>

void get_input(t_init *tmp, char *lim)
{
	char	*line;

	dup2(tmp->fds[0][1], STDOUT_FILENO);
	line = get_next_line(0);
	while (line && ft_strncmp(line, lim, ft_strlen(lim)) != 0)
	{
		write(STDOUT_FILENO, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
}

void	handle_first(t_init *tmp, char **argv, char **envp)
{
	get_input(tmp, argv[2]);
	dup2(tmp->fds[0][0], STDIN_FILENO);
	dup2(tmp->fds[1][1], STDOUT_FILENO);
}

void	handle_second(t_init *tmp, char **argv, char **envp)
{
	tmp->fd1 = open(argv[5], O_RDWR | O_APPEND | O_TRUNC, 0777);
	if (tmp->fd1 == -1)
		exit(EXIT_FAILURE);
	dup2(tmp->fds[1][0], STDIN_FILENO);
	dup2(tmp->fd1, STDOUT_FILENO);
	close(tmp->fd1);
}

void	here_doc_exec(char **argv, char **envp)
{
	t_init	*tmp;
	int		i;

	i = 0;
	tmp = allocate_memory(3);
	if (tmp)
	{
		while (i < 2)
		{
			tmp->pids[i] = fork();
			if (tmp->pids[i] == 0)
			{
				if (i == 0)
					handle_first(tmp, argv, envp);
				if (i == 1)
					handle_second(tmp, argv, envp);
				close_pipes(tmp->fds, 2);
				execute_command(argv[3 + i], envp);
			}
			else if (tmp->pids[i] == -1)
				exit(EXIT_FAILURE);
			i++;
		}
		close_pipes(tmp->fds, 2);
		wait_all_childs(tmp->pids, 2);
	}
}