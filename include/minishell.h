/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:54:12 by rlins             #+#    #+#             */
/*   Updated: 2022/10/29 08:40:56 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h> // Printf
# include <stdlib.h> // Malloc, Free
# include <fcntl.h> // Open
# include <unistd.h> // read, execve

/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int
 */
int		start(int argc, char **argv, char **envp);

/**
 * @brief Simple Printf - Print and format data in console.
 * @include <stdio.h>
 */
void	aux_printf();

/**
 * @brief Simple Malloc - Dynamic memory allocation
 * @include <stdlib.h>
 */
char	*aux_malloc();

/**
 * @brief Simple Free - Free memory from previous allocation
 * @param str ref Variable to free
 * @include <stdlib.h>
 */
void	aux_free(char *str);

/**
 * @brief Simple Write.
 * @include <unistd.h>
 */
void	aux_write();

/**
 * @brief Write 2.
 * @param fd - The file descriptor of where to write the output. You can
 * either use a file descriptor obtained from the open system call, or you
 * can use 0, 1, or 2, to refer to standard input, standard output, or standard
 * error, respectively.
 * @param buf - A pointer to a buffer
 * @param nbytes - The number of bytes to write. If smaller than the provided
 * buffer, the output is truncated.
 * @return Nro bytes written. If negative, then error.
 */
int	aux_write2(int fd, const void *buf, size_t nbytes);

/** [Pipex - Generate output file]
 * @brief Open/create a file
 * @return int. (0) It's OK.
 * @include: <fcntl.h>
 */
int	aux_open();


/**
 * @brief reads cnt bytes of input into the memory area indicated by buf.
 * A successful read() updates the access time for the file.
 */
void aux_read();


/** [Pipex - Check if command is accessible from the current Path]
 * @brief Verify if the access is correct to some program / execution
 * TR command, is available in this path: [/usr/bin/tr]. Access with root in
 * terminal (sudo su) and try to access this path. You will find the file tr.
 * This path is not available: [/home/rlins/.asdf/shims/tr]
 * @return (0) if correct
 * @include <unistd.h>
 */
int	aux_access(char *path_cmd);

/** [Pipex - Responsible to exec the command.]
 * @brief Execute a File
 * @param envp: environment pointer
 * @param cmd: Command to be executed
 * @include: <unistd.h>
 */
void aux_execve(char **envp, char *cmd);


/** [Pipex - Divide the process to execute the command and keep the man process]
 * @brief: Creates a new process by duplicating the calling process. The New
 * process is the Child process. The calling is the Parend/main process.
 * @include: <unistd.h>
 */
void	aux_fork();

void	aux_fork2();

#endif
