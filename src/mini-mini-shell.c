/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-mini-shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:29:43 by rlins             #+#    #+#             */
/*   Updated: 2022/11/01 09:26:37 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

static void	lsh_loop();
static char *lsh_read_line();
static char *lsh_read_line2();
static char **lsh_split_line(char *line);
static int lsh_execute(char **args);
static void check_malloc_error(char *buffer);
static int lsh_launch(char **args);

static int lsh_cd(char **args);
static int lsh_help(char **args);
static int lsh_exit(char **args);

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

int lsh_num_builtins () {
	return sizeof(builtin_str) / sizeof(char *);
};


static int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected arguments to \"cd\"\n");
	}
	else
	{
		if ((chdir(args[1]) != 0))
			perror("lsh");
	}
	return (1);
}

static int lsh_help(char **args)
{
	int i;
	printf("Mini mini shell SLH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (int i = 0; i < lsh_num_builtins(); i++)
	{
		printf(" %s", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
  	return (1);
}

static int lsh_exit(char **args)
{
	return (0);
}


void mini_mini_shell()
{
	printf("yep!");
	lsh_loop();
}

static void	lsh_loop()
{
	char *line;
	char **args;
	int  status;

	do {
		printf("> ");

		// line = lsh_read_line();
		line = lsh_read_line2();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);

	} while (status);
}

static void check_malloc_error(char *buffer)
{
	if (!buffer)
	{
		fprintf(stderr, "Allocation error \n");
		exit(EXIT_FAILURE);
	}
}

static char *lsh_read_line2()
{
	char *line = NULL;
	ssize_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("Readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

static char **lsh_split_line(char *line)
{
	int bufsize = TOK_BUFSIZE;
	int position = 0;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char*));

	check_malloc_error(*tokens);

	token = strtok(line, TOK_DELIM);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position > bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			check_malloc_error(*tokens);
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

static int lsh_launch(char **args)
{
	pid_t pid, w_pid;
	int status;

	pid = fork();

	if(pid == 0 )
	{
		// Child
		if (execvp(args[0], args) == -1)
			perror("lsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		// Error on forking
		perror("lsh");
	}
	else
	{
		// parent process
		do {
			w_pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

static int lsh_execute(char **args)
{
	return (1);
}

// Obsolete
static char *lsh_read_line()
{
	int bufsize = BUFFER_SIZE;
	int position  = 0;
	int c;
	char *buffer = malloc(sizeof(char) * bufsize);

	check_malloc_error(buffer);

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			buffer = realloc(buffer, bufsize);
			check_malloc_error(buffer);
		}
	}
}
