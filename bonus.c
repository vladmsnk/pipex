#include "pipex_bonus.h"


void	pipex_bonus(char **argv, char **envp, int argc)
{
	int	cmp;	
	t_init *tmp;

	tmp = allocate_memory(argc - 3);// argc - 3 it is a number of processes
	cmp = 0;
	while (cmp < argc - 3)
	{
		tmp->pids[cmp] = fork();
		if (tmp->pids[cmp] == 0)
		{
			if (cmp == 0)
				redirect_infile(argv[1], tmp->fds[0]);
			else if (cmp == argc - 4)
				redirect_outfile(argv[argc - 1], tmp->fds[cmp - 1]);
			else
				manage_pipes(cmp, tmp->fds, argc - 4);
			close_pipes(tmp->fds, argc - 4); 
			execute_command(argv[cmp + 2], envp);
		}
		else if (tmp->pids[cmp] < 0)
			exit(EXIT_FAILURE);
		cmp++;
	}
	wait_all_childs(tmp->pids, argc - 3);
}

int main(int argc, char **argv, char **envp)
{
	if (envp && argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0 && argc == 6)
			// here_doc_exec(argv, envp, argc);
			exit(1);
		else
			pipex_bonus(argv, envp, argc);
	}
	else
		exit(EXIT_FAILURE);
    return (0);
}
			// pipex_here_doc(argv, envp, argc);
