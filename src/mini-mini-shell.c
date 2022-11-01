/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-mini-shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:29:43 by rlins             #+#    #+#             */
/*   Updated: 2022/10/31 21:11:37 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

static void	lsh_loop();
static char *lsh_read_line();
static char **lsh_split_line(char *line);
static int lsh_execute(char **args);


void mini_mini_shell()
{
	printf("yep!");
	lsh_loop();
}

char *lsh_read_line()
{
	int bufsize = BUFFER_SIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
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
