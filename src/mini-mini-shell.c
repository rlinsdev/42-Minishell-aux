/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-mini-shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:29:43 by rlins             #+#    #+#             */
/*   Updated: 2022/11/01 08:20:36 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

static void	lsh_loop();
static char *lsh_read_line();
static char *lsh_read_line2();
static char **lsh_split_line(char *line);
static int lsh_execute(char **args);
static void check_malloc_error(char *buffer);


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

	check_malloc_error(tokens);

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
