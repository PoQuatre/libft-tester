/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:49:35 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/12 03:38:31 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char tab[100];

	memset(tab, 0, 100);
	char *ret = ft_memset(tab, 'A', 0);

	/* 1 */ check(tab[0] == 0 && ret == tab);

	memset(tab, 0, 100);
	ret = ft_memset(tab, 'A', 42);
	int c = 0;
	while (c < 100 && tab[c] == 'A') c++;

	/* 3 */ check(c == 42 && tab[42] == 0 && ret == tab);

	memset(tab, 0, 100);
	ret = ft_memset(tab, 'A' + 256, 42);
	c = 0;
	while (c < 100 && tab[c] == 'A') c++;

	/* 4 */ check(c == 42 && tab[42] == 0 && ret == tab);
}
