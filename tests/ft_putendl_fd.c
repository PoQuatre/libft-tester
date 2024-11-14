/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:12 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 18:55:02 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	int fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	ft_putendl_fd("Hello 42!", fd);
	lseek(fd, SEEK_SET, 0);
	char s[20] = {0};
	read(fd, s, 20);
	/* 1 */ check(!strcmp(s, "Hello 42!\n"));
	close(fd);
}
