#include "pipex.h"

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

char	*ger_right_cmd(char *cmd, char **envp)
{
	char	*right_cmd;
	char	**splited_path;
	char	**splited_cmd;
	int		i;

	splited_cmd = ft_split(cmd, ' ');
	if (access(splited_cmd[0], X_OK) == 0)
			return (splited_cmd[0]);
	splited_path = ft_split(extract_paths(envp), ':');
	i = 0;
	while (splited_path[i])
	{
		right_cmd = ft_strjoin(splited_path[i++], "/");
		right_cmd = ft_strjoin(right_cmd, splited_cmd[0]);
		if (access(right_cmd, X_OK) == 0)
			return (right_cmd);
	}
	return (NULL);
}