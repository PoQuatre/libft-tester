/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:08:13 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/07 23:10:48 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "utils.h"

static int g_test_id = 1;

void	handle_segv(int sig)
{
	(void) sig;
}

void	check(bool ok)
{
	if (ok)
		printf(" %s[%d.OK]", CLR_OK, g_test_id++);
	else
		printf(" %s[%d.KO]", CLR_KO, g_test_id++);
}
