/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:37:18 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 17:41:01 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

char	addIndex(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char *s = ft_strmapi("1234", addIndex);
	/* 1 */ check(s && !strcmp(s, "1357"));
	/* 2 */ mcheck(s, 5);
	free(s);

	s = ft_strmapi("", addIndex);
	/* 1 */ check(s && !strcmp(s, ""));
	/* 2 */ mcheck(s, 1);
	free(s);
}
