#include "pipex_bonus.h"

void    here_doc_exec(int argc, char **argv, char **envp, int *fds1, int *fds2)
{

    char	*line;

	line = get_next_line(0);
	dup2(fds1[1], STDOUT_FILENO);
	close(fds1[1]);
	while (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}