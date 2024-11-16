/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:37:07 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/16 01:56:04 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1 */ check(ft_strncmp("t", "", 0) == 0);
	/* 2 */ check(ft_strncmp("1234", "1235", 3) == 0);
	/* 3 */ check(ft_strncmp("1234", "1235", 4) < 0);
	/* 4 */ check(ft_strncmp("1234", "1235", -1) < 0);
	/* 5 */ check(ft_strncmp("", "", 42) == 0);
	/* 6 */ check(ft_strncmp("Hello 42!", "Hello 42!", 42) == 0);
	/* 7 */ check(ft_strncmp("Hello 42!", "hello 42!", 42) < 0);
	/* 8 */ check(ft_strncmp("Hello 42!", "HeLlo 42!", 42) > 0);
	/* 9 */ check(ft_strncmp("Hello 42!", "Hello 42 ", 42) > 0);
	/* 10 */ check(ft_strncmp("Hello 42!", "Hello 42!X", 42) < 0);
	/* 11 */ check(ft_strncmp("Hello 42!", "Hello 42", 42) > 0);
	/* 12 */ check(ft_strncmp("", "1", 0) == 0);
	/* 13 */ check(ft_strncmp("1", "", 0) == 0);
	/* 14 */ check(ft_strncmp("", "1", 1) < 0);
	/* 15 */ check(ft_strncmp("1", "", 1) > 0);
	/* 16 */ check(ft_strncmp("", "", 1) == 0);
	/* 16 */ check(ft_strncmp("test\x80", "test", -1) > 0);
}
