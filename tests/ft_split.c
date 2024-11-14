/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:21:27 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 14:51:06 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char **tab = ft_split("  Hello  42!    ", ' ');
	/* 1 */ mcheck(tab, sizeof(char *) * 3);
	/* 2 */ check(tab && tab[0] && !strcmp(tab[0], "Hello"));
	/* 3 */ mcheck(tab[0], 6);
	/* 4 */ check(tab && tab[1] && !strcmp(tab[1], "42!"));
	/* 5 */ mcheck(tab[1], 4);
	/* 6 */ check(tab && !tab[2]);
	free_tab(tab);

	tab = ft_split("42paris", 0);
	/* 7  */ mcheck(tab, sizeof(char *) * 2);
	/* 8  */ check(tab && tab[0] && !strcmp(tab[0], "42paris"));
	/* 9  */ mcheck(tab[0], 8);
	/* 10 */ check(tab && !tab[1]);
	free_tab(tab);

	tab = ft_split("      ", ' ');
	/* 11 */ mcheck(tab, sizeof(char *) * 1);
	/* 12 */ check(tab && !tab[0]);
	free_tab(tab);

	tab = ft_split("", ' ');
	/* 13 */ mcheck(tab, sizeof(char *) * 1);
	/* 14 */ check(tab && !tab[0]);
	free_tab(tab);

	char *splitme = strdup("--4---2-----42----21---84-");
	tab = ft_split(splitme, '-');
	/* 15 */ mcheck(tab, sizeof(char *) * 6);
	/* 16 */ check(tab && tab[0] && !strcmp(tab[0], "4"));
	/* 17 */ mcheck(tab[0], 2);
	/* 18 */ check(tab && tab[1] && !strcmp(tab[1], "2"));
	/* 19 */ mcheck(tab[1], 2);
	/* 20 */ check(tab && tab[2] && !strcmp(tab[2], "42"));
	/* 21 */ mcheck(tab[2], 3);
	/* 22 */ check(tab && tab[3] && !strcmp(tab[3], "21"));
	/* 23 */ mcheck(tab[3], 3);
	/* 24 */ check(tab && tab[4] && !strcmp(tab[4], "84"));
	/* 25 */ mcheck(tab[4], 3);
	/* 26 */ check(tab && !tab[5]);
	free_tab(tab);
	free(splitme);
}
