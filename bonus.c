#include "pipex_bonus.h"

void	pipex_bonus(char **argv, char **envp, int argc)
{
	int	cmp;	
	int	num_of_cmds;
	t_init *tmp;

	tmp = allocate_memory(argc - 3);
	cmp = 0;
	num_of_cmds = argc - 3;
	while (cmp < num_of_cmds)
	{
		tmp->pids[cmp] = fork();
		if (tmp->pids[cmp] == 0)
		{
			if (cmp == 0)
				redirect_infile(argv[1], tmp->fds[0]);
			else if (cmp == num_of_cmds - 1)
				redirect_outfile(argv[argc - 1], tmp->fds[cmp - 1]);
			else
				manage_pipes(cmp, tmp->fds, num_of_cmds - 1);
			close_pipes(tmp->fds, num_of_cmds - 1);
			execute_command(argv[cmp + 2], envp);
		}
		else if (tmp->pids[cmp] < 0)
			exit(EXIT_FAILURE);
		cmp++;
	}
	wait_all_childs(tmp->pids, num_of_cmds);
}

int main(int argc, char **argv, char **envp)
{
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