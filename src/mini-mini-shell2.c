/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-mini-shell2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:40:34 by rlins             #+#    #+#             */
/*   Updated: 2022/11/10 16:25:01 by rlins            ###   ########.fr       */
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
static void parse_space(char *str, char **parsed);
static int	own_cmd_handler(char **parsed);
static void help();
static void exec_args_piped(char **parsed, char **parsed_pipe);
static void exec_args(char **parsed);

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
		/* execFlag -
		* 0 if there is no command or Builtin command
		* 1 if a simple command
		* 2 if including pipe. */
		execFlag = process_string(input_string, parsed_args, parsed_args_piped);

		if (execFlag == 1)
			exec_args(parsed_args);

		//exit(EXIT_SUCCESS);
	}

}

static void exec_args_piped(char **parsed, char **parsed_pipe)
{

}
static void exec_args(char **parsed)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("error on forking");
		return;
	}
	else if (pid == 0)
	{
		if (execvp(parsed[0], parsed) < 0)
			printf("error on execute command");
		exit(0);
	}
	else
	{
		// Wait for child
		wait(NULL);
		return ;
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

	if (piped)
	{
		parse_space(str_piped[0], parsed);
		parse_space(str_piped[1], parsed_pipe);
	}
	else
	{
		parse_space(str, parsed);
	}

	if (own_cmd_handler(parsed))
	{


	}
}

/**
 * @brief Execute Builtin commands
 * @param parsed
 * @return int
 */
static int own_cmd_handler(char **parsed)
{
	int nro_cmd = 4, i, switch_own_arg = 0;
	char *lst_of_nro_cmd[nro_cmd];
	char *username;

	lst_of_nro_cmd[0] = "exit";
	lst_of_nro_cmd[1] = "cd";
	lst_of_nro_cmd[2] = "help";
	lst_of_nro_cmd[3] = "hello";

	for (i = 0; i < nro_cmd; i++)
	{
		if (strcmp(parsed[0], lst_of_nro_cmd[i]) == 0)
		{
			switch_own_arg = i + 1;
			break;
		}
	}

	switch (switch_own_arg)
	{
		case 1:
			printf("\nGoodBye\n");
			exit(0);
		case 2:
			chdir(parsed[1]);
		case 3:
			help();
			return (1);
		case 4:
			username = getenv("USER");
			printf("\nHello %s", username);
			return (1);
		default:
			break;
	}
	return (0);
}

static void help()
{
	puts("Welcome to the jungle!");
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
 * @brief function for parsing command words
 * @param str
 * @param parsed
*/
static void parse_space(char *str, char **parsed)
{
	int i;

	for (i = 0; i < MAXLIST; i++)
	{
		parsed[i] = strsep(&str, " ");
		if (parsed[i] == NULL)
			break;
		if (strlen(parsed[i]) == 0)
			i--;
	}

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
