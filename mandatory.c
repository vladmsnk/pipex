#include "pipex.h"


void	run_pipex(int argc, char **argv, char **envp, t_init *tmp)
{
	
}
void	pipex(int argc, char **argv, char **envp)
{
	t_init *tmp;
	int		i;

	tmp = allocate_memory();
	if (tmp)
	{
		if (pipe(tmp->fds) == -1)
			clean_variables(tmp, EXIT_FAILURE);
		run_pipex(argc, argv, envp, tmp);
	}
	else
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	if (envp && argc == 5)
		pipex(argc, argv, envp);
	else
		exit(EXIT_FAILURE);
	return (0);
}