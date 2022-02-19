#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct s_init
{
	int **fds;
	int *pids;
	int in_fd;
	int out_fd;

}	t_init;


t_init	*allocate_memory(int proc_num);

#endif