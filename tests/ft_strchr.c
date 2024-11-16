/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:22:50 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/16 07:30:34 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char s[] = "Hello 42!";

	/* 1 */ check(ft_strchr(s, 'H') == s);
	/* 2 */ check(ft_strchr(s, 'l') == s + 2);
	/* 3 */ check(ft_strchr(s, 'z') == NULL);
	/* 4 */ check(ft_strchr(s, 0) == s + 9);
	/* 5 */ check(ft_strchr(s, 'H' + 256) == s);
	/* 6 */ check(ft_strchr(s, '\0' + 256) == s + 9);
}
