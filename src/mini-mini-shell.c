/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-mini-shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:29:43 by rlins             #+#    #+#             */
/*   Updated: 2022/11/01 07:41:48 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

static void	lsh_loop();
static char *lsh_read_line();
static char **lsh_split_line(char *line);
static int lsh_execute(char **args);
static void check_buffer_error(char *buffer);


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

		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);

	} while (status);
}

static void check_buffer_error(char *buffer)
{
	if (!buffer)
	{
		fprintf(stderr, "Allocation error \n");
		exit(EXIT_FAILURE);
	}
}

static char *lsh_read_line()
{
	int bufsize = BUFFER_SIZE;
	int position  = 0;
	int c;
	char *buffer = malloc(sizeof(char) * bufsize);

	check_buffer_error(buffer);

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
			check_buffer_error(buffer);
		}
	}
}
