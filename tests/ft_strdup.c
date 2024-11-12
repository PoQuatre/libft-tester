/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:15:56 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/12 02:28:57 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char *hello = "Hello 42!";
	char *empty = "";

	char *s = ft_strdup(hello);
	/* 1 */ check(s != hello);
	/* 2 */ check(!strcmp(s, hello));
	/* 3 */ mcheck(s, strlen(hello) + 1);
	free(s);

	s = ft_strdup(empty);
	/* 4 */ check(s != empty);
	/* 5 */ check(!strcmp(s, empty));
	/* 6 */ mcheck(s, strlen(empty) + 1);
	free(s);
}
