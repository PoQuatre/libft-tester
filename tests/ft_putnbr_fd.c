/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:38:12 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 19:18:02 by mle-flem         ###   ########.fr       */
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
	ft_putnbr_fd(0, fd);
	lseek(fd, SEEK_SET, 0);
	char s[20] = {0};
	read(fd, s, 20);
	/* 1 */ check(!strcmp(s, "0"));
	close(fd);

	fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	ft_putnbr_fd(10, fd);
	lseek(fd, SEEK_SET, 0);
	bzero(s, 20);
	read(fd, s, 20);
	/* 2 */ check(!strcmp(s, "10"));
	close(fd);

	fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	ft_putnbr_fd(-10, fd);
	lseek(fd, SEEK_SET, 0);
	bzero(s, 20);
	read(fd, s, 20);
	/* 3 */ check(!strcmp(s, "-10"));
	close(fd);

	fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	ft_putnbr_fd(2147483647, fd);
	lseek(fd, SEEK_SET, 0);
	bzero(s, 20);
	read(fd, s, 20);
	/* 4 */ check(!strcmp(s, "2147483647"));
	close(fd);

	fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	ft_putnbr_fd(-2147483648, fd);
	lseek(fd, SEEK_SET, 0);
	bzero(s, 20);
	read(fd, s, 20);
	/* 5 */ check(!strcmp(s, "-2147483648"));
	close(fd);

	fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	ft_putnbr_fd(42, fd);
	lseek(fd, SEEK_SET, 0);
	bzero(s, 20);
	read(fd, s, 20);
	/* 6 */ check(!strcmp(s, "42"));
	close(fd);

	fd = open("/tmp", O_RDWR | O_TMPFILE | O_TRUNC);
	ft_putnbr_fd(-42, fd);
	lseek(fd, SEEK_SET, 0);
	bzero(s, 20);
	read(fd, s, 20);
	/* 7 */ check(!strcmp(s, "-42"));
	close(fd);
}
