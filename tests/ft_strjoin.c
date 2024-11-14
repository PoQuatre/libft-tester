/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:09:30 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 07:13:27 by mle-flem         ###   ########.fr       */
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

	char *s = ft_strjoin("Hello", " 42!");
	/* 1 */ check(s && !strcmp(s, "Hello 42!"));
	/* 2 */ mcheck(s, 10);
	free(s);

	s = ft_strjoin("", "42");
	/* 3 */ check(s && !strcmp(s, "42"));
	/* 4 */ mcheck(s, 3);
	free(s);

	s = ft_strjoin("42", "");
	/* 5 */ check(s && !strcmp(s, "42"));
	/* 6 */ mcheck(s, 3);
	free(s);

	s = ft_strjoin("", "");
	/* 7 */ check(s && !strcmp(s, ""));
	/* 8 */ mcheck(s, 1);
	free(s);
}
