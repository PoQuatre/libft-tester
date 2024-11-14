/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:09:56 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 02:32:52 by mle-flem         ###   ########.fr       */
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

	char *s = ft_substr("Hello 42!", 0, 42000);
	/* 1 */ check(s && !strcmp(s, "Hello 42!"));
	/* 2 */ mcheck(s, strlen("Hello 42!") + 1);
	free(s);

	s = ft_substr("Hello 42!", 1, 1);
	/* 3 */ check(s && !strcmp(s, "e"));
	/* 4 */ mcheck(s, 2);
	free(s);

	s = ft_substr("Hello 42!", 100, 100);
	/* 5 */ check(s && !strcmp(s, ""));
	/* 6 */ mcheck(s, 1);
	free(s);

	char *str = strdup("0123456789");
	s = ft_substr(str, 9, 10);
	/* 7 */ check(s && !strcmp(s, "9"));
	/* 8 */ mcheck(s, 2);
	free(s);
	free(str);

	s = ft_substr("42", 0, 0);
	/* 9  */ check(s && !strcmp(s, ""));
	/* 10 */ mcheck(s, 1);
	free(s);

	s = ft_substr("test", 1, 2);
	/* 11 */ check(s && !strcmp(s, "es"));
	/* 12 */ mcheck(s, 3);
	free(s);
}
