/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:12 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 23:37:23 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

#include "libft.h"

static int	g_fd;

void	content_del(void *content)
{
	write(g_fd, &"0123456789"[(size_t) content], 1);
}

int	qsort_compare(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	g_fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	t_list *l = ft_lstnew(0);
	for (size_t i = 1; i < 10; i++)
		ft_lstadd_back(&l, ft_lstnew((void *) i));
	ft_lstclear(&l, content_del);
	lseek(g_fd, SEEK_SET, 0);
	char s[15] = {0};
	read(g_fd, s, 15);
	qsort(s, strlen(s), 1, qsort_compare);
	/* 1 */ check(!strcmp(s, "0123456789"));
	/* 2 */ check(!l);
	close(g_fd);
}
