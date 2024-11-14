/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:12 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 23:07:48 by mle-flem         ###   ########.fr       */
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
	free(content);
	write(g_fd, "ok", 2);
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	g_fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	t_list *l = ft_lstnew(malloc(1));
	ft_lstdelone(l, content_del);
	lseek(g_fd, SEEK_SET, 0);
	char s[10] = {0};
	read(g_fd, s, 10);
	/* 1 */ check(!strcmp(s, "ok"));
	close(g_fd);
}
