/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:35:02 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/09 06:21:00 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char src[] = "Hello 42!";
	char dst[20];
	memset(dst, 'A', 20);

	/* 1 */ check(ft_strlcpy(dst, src, 0) == strlen(src) && dst[0] == 'A');
	/* 2 */ check(ft_strlcpy(dst, src, 1) == strlen(src) && dst[0] == 0 && dst[1] == 'A');
	/* 3 */ check(ft_strlcpy(dst, src, 2) == strlen(src) && dst[0] == 'H' && dst[1] == 0 && dst[2] == 'A');
	/* 4 */ check(ft_strlcpy(dst, src, -1) == strlen(src) && !strcmp(src, dst) && dst[10] == 'A'); memset(dst, 'A', 20);
	/* 5 */ check(ft_strlcpy(dst, src, 9) == strlen(src) && !memcmp(src, dst, 8) && dst[8] == 0); memset(dst, 'A', 20);
	/* 6 */ check(ft_strlcpy(dst, src, 10) == strlen(src) && !memcmp(src, dst, 10)); memset(dst, 'A', 20);
	/* 7 */ check(ft_strlcpy(dst, src, 11) == strlen(src) && !memcmp(src, dst, 10) && dst[10] == 'A'); memset(dst, 'A', 20);
	/* 8 */ check(ft_strlcpy(dst, "", 42) == 0 && dst[0] == 0 && dst[1] == 'A'); memset(dst, 0, 20);
	/* 9 */ check(ft_strlcpy(dst, "1", 0) == 1 && dst[0] == 0); memset(dst, 'A', 20);
}
