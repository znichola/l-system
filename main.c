/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:38:00 by marvin            #+#    #+#             */
/*   Updated: 2022/11/22 13:38:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsystem.h"


/**
 * @brief string manipulation program
 * 
 * @param argv[1] variables		AB
 * @param argv[2] constants		[]
 * @param argv[3] axiom/start	A
 * @param argv[4] rules 		A AB B A 
 */

int	rule_applicator(char **src, char **ret, t_genus *g)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	// while (g->rules[i])
	while (g->consts[i]) // TODO finish this condition and it should be done
	{
		printf("checking src<%c> rule<%c> const<%c>\n", **src, g->rules[i]->initial[0], g->consts[j]);
		if (g->rules[i]->initial[0] == **src)
		{
			printf("applied rule:%d ", i);
			dump_rule(g->rules[i]); printf("\n");
			int t = ft_strlcpy(*ret, g->rules[i]->result, 20);
			// printf("new ret:<%s>\n", *ret);
			*ret += t;
			break ;
		}
		else if (g->consts[j] == **src)
		{
			printf("copying const:%c\n", g->consts[j]);
			**ret = g->consts[j];
			// printf("new ret:<%s>\n", *ret);
			*ret += 1;
			break ;
		}
		// if (!(i < g->nr && j < g->nc))
		// 	return (SUCCESS);
		if (i < g->nr - 1)
			i++;
		if (j < g->nc - 1)
			j++;
		printf("as,ldjklasdjaskld i:%d nr:%d, j:%d nc:%d\n", i, g->nr, j, g->nc);
	}
		printf("i:%d nr:%d, j:%d nc:%d\n", i, g->nr, j, g->nc);
	*src += 1;
	// printf("end\n");
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_genus		g;
	t_strplus	alice;
	t_strplus	bob;
	t_strplus	tmp;

	init_strplus(&alice);
	init_strplus(&bob);
	// tmp = (char *)calloc(10000, sizeof(char));
	if (init_genus(&g, argv + 1))
		return (-1);
	printf("init genus finished\n");
	dump_genus(&g);
	alice.root[0] = g.axiom[0];

	for (int i = 1; i < 3; i++)
	{
		printf("\n -- NEW ITTERATION --\na:<%s>\nb:<%s>\n", alice.root, bob.root);
		while (*alice.seek)
		{
			rule_applicator(&alice.seek, &bob.seek, &g);
			printf("bob:<%s>\n", bob.root);
		}
		printf("n = %d : %s\n", i, bob.root);
		// printf("---alice:<%s>\n---bob:<%s>\n", alice.root, bob.root);
		tmp = alice;
		alice = bob;
		bob = tmp;  
		reset_strplus(&bob, 1);
		reset_strplus(&alice, 0);
	}
	return (0);
}