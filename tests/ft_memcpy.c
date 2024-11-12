/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:59:30 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/12 13:40:03 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char dst[100];

	memset(dst, 'A', 100);
	char *ret = ft_memcpy(dst, "Hello 42!", 0);

	/* 1 */ check(dst[0] == 'A' && ret == dst);

	memset(dst, 'A', 100);
	ret = ft_memcpy(dst, NULL, 0);

	/* 2 */ check(dst[0] == 'A' && ret == dst);

	memset(dst, 'A', 100);
	char src[42];
	memset(src, 'B', 42);
	ret = ft_memcpy(dst, src, 21);
	int c = 0;
	while (c < 100 && dst[c] == 'B') c++;

	/* 3 */ check(c == 21 && dst[42] == 'A' && ret == dst);
}
