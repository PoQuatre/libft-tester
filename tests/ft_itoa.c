/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:36:50 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 16:11:12 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char *s = ft_itoa(INT_MAX);
	/* 1 */ check(s && !strcmp(s, "2147483647"));
	/* 2 */ mcheck(s, 11);
	free(s);

	s = ft_itoa(INT_MIN);
	/* 3 */ check(s && !strcmp(s, "-2147483648"));
	/* 4 */ mcheck(s, 12);
	free(s);

	s = ft_itoa(0);
	/* 5 */ check(s && !strcmp(s, "0"));
	/* 6 */ mcheck(s, 2);
	free(s);

	s = ft_itoa(1);
	/* 7 */ check(s && !strcmp(s, "1"));
	/* 8 */ mcheck(s, 2);
	free(s);

	s = ft_itoa(-1);
	/* 9  */ check(s && !strcmp(s, "-1"));
	/* 10 */ mcheck(s, 3);
	free(s);

	s = ft_itoa(10);
	/* 11 */ check(s && !strcmp(s, "10"));
	/* 12 */ mcheck(s, 3);
	free(s);

	s = ft_itoa(-10);
	/* 13 */ check(s && !strcmp(s, "-10"));
	/* 14 */ mcheck(s, 4);
	free(s);

	s = ft_itoa(42);
	/* 15 */ check(s && !strcmp(s, "42"));
	/* 16 */ mcheck(s, 3);
	free(s);
}
