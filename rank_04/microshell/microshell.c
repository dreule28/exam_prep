#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void	ft_putstr(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	print_error(char *msg, char *arg)
{
	ft_putstr(2, msg);
	if (arg)
		ft_putstr(2, arg);
	write(2, "\n", 1);
}

void	ft_cd(char *arg)
{
	if (chdir(arg))
		print_error("error: cd: cannot change directory to ", arg);
}

void	ft_execute(char **argv, char **env, int i, int tmp_fd)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	execve(argv[0], argv, env);
	print_error("error: cannot execute ", argv[0]);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	int i = 0;
	int fd[2];
	int tmp_fd = dup(STDIN_FILENO);

	if (argc == 1)
		return (0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (!strcmp(argv[0], "cd"))
		{
			if (i != 2)
				print_error("error: cd: bad arguments", NULL);
			ft_cd(argv[1]);
		}
		else if (i != 0 && (!argv[i] || !strcmp(argv[i], ";")))
		{
			if (fork() == 0)
				ft_execute(argv, env, i, tmp_fd);
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, 0) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && !strcmp(argv[i], "|"))
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				close(fd[0]);
				ft_execute(argv, env, i, tmp_fd);
			}
			else
			{
				close(tmp_fd);
				close(fd[1]);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	return (0);
}