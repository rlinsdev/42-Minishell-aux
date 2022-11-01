/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:54:12 by rlins             #+#    #+#             */
/*   Updated: 2022/11/01 08:09:09 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 1024;
# define TOK_BUFSIZE 64;
# define TOK_DELIM " \t\r\n\a"

# include <libft.h>
# include <stdio.h> // Printf
# include <stdlib.h> // Malloc, Free, exit
# include <fcntl.h> // Open
# include <unistd.h> // read, execve, fork, pipe
# include <sys/wait.h> // waitpid
# include <signal.h> // signal
// # include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>

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
 * process is the Child process. The calling is the Parent/main process.
 * @include: <unistd.h>
 */
void	aux_fork();

void	aux_fork2();

/** [Pipex - Output from one to standard input of another]
 * @brief Is the same a pipe in console. I Will try to apply this command here:
 * $> ping -c 5 google.com | grep rtt
 * @include: <unistd.h>
 * @include: <sys/wait.h> (Waitpid)
 * @return: (0) if it's OK.
 */
int	aux_pipe();

/** [Deprecated: https://man7.org/linux/man-pages/man2/signal.2.html]
 * @brief: A signal is an event which is generated to notify a process or
 * thread that some important situation has arrived. When a process or thread
 * has received a signal, the process or thread will stop what its doing and
 * take some action. Signal may be useful for inter-process communication.
 * @include: <signal.h>
 */
void	aux_signal();
void	aux_signal2();
void	aux_signal3();

/**
 * @brief: Set the disposition for sig to act, and store the old disposition in
 * oact”. Its return value is 0 or -1, indicating whether the system call
 * errored.
 * Its return value is 0 or -1, indicating whether the system call errored.
 * @include: <signal.h>
 */
int	aux_sigaction();

/**
 * @brief https://www.youtube.com/watch?v=jF-1eFhyz1U
 * @return int
 */
int	aux_sigaction2();


/** [man opendir / man readdir /  ]
 * @brief
 * OpenDir - Open Directory
 * Readdir - Return a pointer to a Dir Ent Structure.
 * CloseDir - Close Directory open by OpenDir
 * Take a look in: DirEnt struct
 * @include: <dirent.h> <sys/types.h>
 */
void	aux_opendir();

/** [https://brennan.io/2015/01/16/write-a-shell-in-c/]
 * @brief Basic sample of 1 Mini-shell. It's smaller that 42 mini-shell, but
 * will help to get a general idea of the project
 */
void mini_mini_shell();



#endif
