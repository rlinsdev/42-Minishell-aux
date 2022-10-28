/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:12:54 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 10:32:05 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	aux_printf()
{
	printf("Begin - Printf:\n");
	printf("hello world\n");
	printf("End - Printf:\n");

	// Carriage return working
	printf("\ra:1");
	printf("\rb:2");
	printf("\rc:3");
	printf("\rd:4");
	printf("\n");
}
