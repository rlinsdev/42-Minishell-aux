/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:41:21 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 13:40:09 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	aux_open()
{
	//O_TRUNC	Initially clear all data from the file.
	//O_CREAT	If the file does not exist, create it. If the O_CREAT option is
	// used, then you must include the third parameter.
	//O_RDWR	Open the file so that it can be read from and written to.
	int fd = open("out.txt", O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd < 0)
		return (1);
	size_t n_bytes = write(fd, "opa!\n", 5);
	int result_close = close(fd);
	return n_bytes;
}
