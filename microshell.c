#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int error(char *str, char *err)
{
	while(*str)
		write(2, str++, 1);
	if(err)
	{
		while(*err)
			write(2, err++, 1);
	}
	write(2, "\n", 1);
	return(1);
}

int execute(char **argv, int i, int fd, char **env)
{
	args[i] = NULL;
	dup2(fd, 0);
	close(fd);
	execve(argv[0], argv, env);
	return(error("error: cannot execute ", argv[0]);
}


int main(int argc, char **argv, char **env)
{
	int i, fd[2], pid, tmp;

	(void)argc;
	i = 0;
	fd = 0;
	pid = 0;
	tmp = 0;
	while(argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while(argv[i] && strcmp(argv[i], "|") && strcmo(argv[i] ";"))
			i++;
		if (!strcmp(arv[0], "cd"))
		{
			if(i != 2)
				error("error: cd: wrong arguments", NULL);
			else if(chdir(argv[1] != 0))
				error("error: cd: cannot change directory to", argv[1]);
		}

	}
	close(tmp);
	return(0);
}
