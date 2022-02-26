#include "pipex_bonus.h"

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
		free(cur_cmd);
	}
	perror("command not found");
	exit(EXIT_FAILURE);
}
