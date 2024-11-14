/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:28:27 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 08:39:21 by mle-flem         ###   ########.fr       */
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

	char *s = ft_strtrim("     Hello 42!      ", " ");
	/* 1 */ check(s && !strcmp(s, "Hello 42!"));
	/* 2 */ mcheck(s, 10);
	free(s);

	s = ft_strtrim(" x x xHello 42!x x x ", " x");
	/* 3 */ check(s && !strcmp(s, "Hello 42!"));
	/* 4 */ mcheck(s, 10);
	free(s);

	s = ft_strtrim(" x xx xyx xx x ", " x");
	/* 5 */ check(s && !strcmp(s, "y"));
	/* 6 */ mcheck(s, 2);
	free(s);

	s = ft_strtrim(" x xx xxx xx x ", " x");
	/* 7 */ check(s && !strcmp(s, ""));
	/* 8 */ mcheck(s, 1);
	free(s);

	s = ft_strtrim("", " x");
	/* 9  */ check(s && !strcmp(s, ""));
	/* 10 */ mcheck(s, 1);
	free(s);

	s = ft_strtrim("42", "");
	/* 11 */ check(s && !strcmp(s, "42"));
	/* 12 */ mcheck(s, 3);
	free(s);

	s = ft_strtrim("", "");
	/* 13 */ check(s && !strcmp(s, ""));
	/* 14 */ mcheck(s, 1);
	free(s);

	s = ft_strtrim("abcdba", "acb");
	/* 15 */ check(s && !strcmp(s, "d"));
	/* 16 */ mcheck(s, 2);
	free(s);
}
