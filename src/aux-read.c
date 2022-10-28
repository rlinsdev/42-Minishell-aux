/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:41:48 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 13:50:02 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

void aux_read()
{
	int size, fd;
	char *c = malloc(10 * sizeof(char));

	fd = open("testfile.txt", O_RDONLY);

	size = read(fd, c, 5);
	free(c);
	close(fd);
}
