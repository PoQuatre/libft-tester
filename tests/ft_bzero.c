/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:41:45 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/13 01:49:28 by mle-flem         ###   ########.fr       */
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
	char s1[] = {42, 21, 84, 4, 2, 0, 2, 1};
	char s2[] = {0, 0, 0, 4, 2, 0, 2, 1};
	char s3[] = {0, 0, 0, 0, 0, 0, 0, 0};

	memcpy(buf, s1, 8);
	ft_bzero(buf, 0);
	/* 1 */ check(!memcmp(buf, s1, 8));

	memcpy(buf, s1, 8);
	ft_bzero(buf, 3);
	/* 2 */ check(!memcmp(buf, s2, 8));

	memcpy(buf, s1, 8);
	ft_bzero(buf, 8);
	/* 3 */ check(!memcmp(buf, s3, 8));
}
