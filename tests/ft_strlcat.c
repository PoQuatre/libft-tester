/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:36:03 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/10 21:17:34 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char src[] = "AAAAAAAAA";
	char dst[30];

	memset(dst, 0, 30); dst[0] = 'B';
	/* 1 */ check(ft_strlcat(dst, src, 0) == 9 && !strcmp(dst, "B"));

	memset(dst, 0, 30); dst[0] = 'B';
	/* 2 */ check(ft_strlcat(dst, src, 1) == 10 && !strcmp(dst, "B"));

	memset(dst, 0, 30); memset(dst, 'B', 4);
	/* 3 */ check(ft_strlcat(dst, src, 3) == 3 + strlen(src) && !strcmp(dst, "BBBB"));

	memset(dst, 0, 30); memset(dst, 'B', 4);
	/* 4 */ check(ft_strlcat(dst, src, 6) == 13 && !strcmp(dst, "BBBBA"));

	memset(dst, 0, 30); memset(dst, 'C', 5);
	/* 5 */ check(ft_strlcat(dst, src, -1) == 14 && !strcmp(dst, "CCCCCAAAAAAAAA"));

	memset(dst, 0, 30); memset(dst, 'C', 15);
	/* 6 */ check(ft_strlcat(dst, src, 17) == 24 && !strcmp(dst, "CCCCCCCCCCCCCCCA"));

	memset(dst, 0, 30);
	/* 7 */ check(ft_strlcat(dst, src, 1) == 9 && !strcmp(dst, ""));

	memset(dst, 0, 30); memset(dst, '1', 10);
	/* 8 */ check(ft_strlcat(dst, src, 5) == 14 && !strcmp(dst, "1111111111"));

	memset(dst, 0, 30); memset(dst, '1', 10);
	/* 9 */ check(ft_strlcat(dst, "", 15) == 10 && !strcmp(dst, "1111111111"));

	memset(dst, 0, 30); memset(dst, '1', 10);
	/* 10 */ check(ft_strlcat(dst, "", 15) == 10 && !strcmp(dst, "1111111111"));

	memset(dst, 0, 30);
	/* 11 */ check(ft_strlcat(dst, "", 42) == 0 && !strcmp(dst, ""));

	memset(dst, 0, 30);
	/* 12 */ check(ft_strlcat(dst, "", 0) == 0 && !strcmp(dst, ""));

	memset(dst, 0, 30);
	/* 13 */ check(ft_strlcat(dst, "123", 1) == 3 && !strcmp(dst, ""));

	memset(dst, 0, 30);
	/* 14 */ check(ft_strlcat(dst, "123", 2) == 3 && !strcmp(dst, "1"));

	memset(dst, 0, 30);
	/* 15 */ check(ft_strlcat(dst, "123", 3) == 3 && !strcmp(dst, "12"));

	memset(dst, 0, 30);
	/* 16 */ check(ft_strlcat(dst, "123", 4) == 3 && !strcmp(dst, "123"));

	memset(dst, 0, 30);
	/* 17 */ check(ft_strlcat(dst, "123", 0) == 3 && !strcmp(dst, ""));
}
