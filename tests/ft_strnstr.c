/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:04:43 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/12 23:20:12 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char *haystack = "aaabcabcd";
	char *needle = "aabc";
	char *empty = "";

	/* 1  */ check(ft_strnstr(haystack, needle, 0) == NULL);
	/* 2  */ check(ft_strnstr(haystack, needle, -1) == haystack + 1);
	/* 3  */ check(ft_strnstr(haystack, "a", -1) == haystack);
	/* 4  */ check(ft_strnstr(haystack, "c", -1) == haystack + 4);
	/* 5  */ check(ft_strnstr(empty, "", -1) == empty);
	/* 6  */ check(ft_strnstr(empty, "", 0) == empty);
	/* 7  */ check(ft_strnstr(empty, "coucou", -1) == NULL);
	/* 8  */ check(ft_strnstr(haystack, "aaabc", 5) == haystack);
	/* 9  */ check(ft_strnstr(empty, "12345", 5) == NULL);
	/* 10 */ check(ft_strnstr(haystack, "abcd", 9) == haystack + 5);
	/* 11 */ check(ft_strnstr(haystack, "cd", 8) == NULL);
	/* 12 */ check(ft_strnstr(haystack, "a", 1) == haystack);
	/* 13 */ check(ft_strnstr("1", "a", 1) == NULL);
	/* 14 */ check(ft_strnstr("22", "b", 2) == NULL);
}
