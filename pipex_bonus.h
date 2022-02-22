#ifndef PIPEX__BONUS_H
# define PIPEX__BONUS_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct s_init
{
	int fd1;
	int fd2;
	int	**fds;
	int *pids;
}	t_init;

//parsing
char	*extract_paths(char **envp);
char	*ger_right_cmd(char *cmd, char **envp);

//initialize and clean
t_init	*allocate_memory(int proc_num);
void	clean_double(int **arr, int len);
void	clean_variables(t_init *tmp, int num_of_pipes, int exit_stat);
void	redirect_infile(char *infile, int *fds_init);
void	redirect_outfile(char *outfile, int *fds_end);
int		**open_pipes(int pipes_num);
void	manage_pipes(int curr_pipe, int **fds, int pipes_num);
void	wait_all_childs(int *pids, int num_of_forks);
void	close_pipes(int **fds, int pipes_num);
void	execute_command(char *cmd, char **envp);
void    here_doc_exec(char **argv, char **envp);

#endif  