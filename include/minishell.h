/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:54:12 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 13:16:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h> // Printf
# include <stdlib.h> // Malloc / Free
# include <fcntl.h> // Open

/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int
 */
int		start(int argc, char **argv);

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
 *
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

/**
 * @brief Open/create a file
 * @return int. (0) It's OK.
 */
int	aux_open();


#endif
