/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:22:50 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/16 07:34:30 by mle-flem         ###   ########.fr       */
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
	char s2[] = "";

	/* 1 */ check(ft_strrchr(s, 'H') == s);
	/* 2 */ check(ft_strrchr(s, 'l') == s + 3);
	/* 3 */ check(ft_strrchr(s, 'z') == NULL);
	/* 4 */ check(ft_strrchr(s, 0) == s + 9);
	/* 5 */ check(ft_strrchr(s, 'H' + 256) == s);
	/* 6 */ check(ft_strrchr(s, '\0' + 256) == s + 9);
	/* 7 */ check(ft_strrchr(s2, 'V') == NULL);
	/* 8 */ check(ft_strrchr(s2, 0) == s2);
}
