/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:45:20 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/12 13:59:37 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char buf[8] = {0};
	char s1[] = {42, 82, 21, 4, 2, 0, 2, 1};
	char s2[] = {21, 4, 21, 4, 2, 0, 2, 1};
	char s3[] = {21, 21, 4, 4, 2, 0, 2, 1};

	memset(buf, 0, 8);
	/* 1 */ check(ft_memmove(buf, s1, 8) == buf && !memcmp(buf, s1, 8));

	memcpy(buf, s1, 8);
	/* 2 */ check(ft_memmove(buf, buf + 2, 0) == buf && !memcmp(buf, s1, 8));

	memcpy(buf, s1, 8);
	/* 2 */ check(ft_memmove(buf, buf + 2, 2) == buf && !memcmp(buf, s2, 8));

	memcpy(buf, s2, 8);
	/* 2 */ check(ft_memmove(buf + 1, buf, 2) == buf + 1 && !memcmp(buf, s3, 8));
}
