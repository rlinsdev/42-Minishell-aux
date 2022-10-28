/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:38:39 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 11:04:26 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char*	aux_malloc()
{
	char *str1;
	str1 = malloc(5);
	strcpy(str1, "Test");
	printf("Value: %s Address: %p\n", str1, str1); // 0x5555555596b0
	return (str1);
	// free(str1);
}
