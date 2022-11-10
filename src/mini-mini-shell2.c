/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-mini-shell2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:40:34 by rlins             #+#    #+#             */
/*   Updated: 2022/11/10 14:21:22 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/making-linux-shell-c/
#include <minishell.h>

#define MAXCOM 1000 // max number of commands to be supported
#define MAXLIST 100 // max number of letters to be supported

// Clearing the shell using escape sequences
#define clear() printf("\033[H\033[J")

static void init_shell();
static void printDir();
static int	take_input(char *str);
static int 	process_string(char *str, char **parsed, char **parsed_pipe);
static int 	parse_pipe(char *str, char **str_piped);

void mini_mini_shell2()
{
	char input_string[MAXCOM];
	char *parsed_args[MAXLIST];
	char *parsed_args_piped[MAXLIST];
	int execFlag = 0;

	init_shell();

	while (1)
	{
		printDir();
		if (take_input(input_string))
			continue;
		// process
		execFlag = process_string(input_string, parsed_args, parsed_args_piped);

		exit(EXIT_SUCCESS);
	}

}

/**
 * @brief Function to take input
 * @param str
 * @return int
 */
static int	take_input(char *str)
{
	char	*buf;
	buf = readline("\n>>> ");
	if (strlen(buf) != 0)
	{
		add_history(buf);
		strcpy(str, buf);
		return (0);
	}
	else
		return (1);
}

/**
 * @brief Print current directory
 *
 */
static void printDir()
{
	// Current work directory
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

/**
 * @brief
 *
 * @param str
 * @param parsed
 * @param parsed_pipe
 * @return int
 */
static int process_string(char *str, char **parsed, char **parsed_pipe)
{
	char *str_piped[2];
	int piped = 0;

	piped = parse_pipe(str, str_piped);

}

static int parse_pipe(char *str, char **str_piped)
{
	int i;
	for (i=0; i<1; i++)
	{
		str_piped[i] = strsep(&str, "|");
		
		if (str_piped[i] == NULL)
			break;
	}
	if (str_piped[1] == NULL)
		return (0);
	else
		return (1);
}

/**
 * @brief Greeting shell in initialization
 */
static void init_shell()
{
	clear();
	printf("\n\n\n\n******************************************");
	printf("\n\n\n\t****MY SHELL****");
	printf("\n\n\t-USE AT YOUR OWN RISK-");
	printf("\n\n\n\n******************************************");
	char *user_name = getenv("USER");
	printf("\n\n\nUSER is: @%s", user_name);
	printf("\n");
	sleep(1);
	clear();
}
