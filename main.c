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
	int	len;

	i = 0;
	while (g->rules[i])
	{
		// printf("checking src<%c> rule<%c>\n", **src, g->rules[i]->initial[0]);
		if (g->rules[i]->initial[0] == **src)
		{
			// printf("applied rule:%d ", i);
			// dump_rule(g->rules[i]); printf("\n");
			*ret += ft_strlcpy(*ret, g->rules[i]->result, 10);
			*src += 1;
			return (SUCCESS);
		}
		i++;
	}
	*src += 1;
	// printf("end\n");
}

int	init_strplus(t_strplus *s)
{
	printf("ljksdf\n");
	s->root = (char *)calloc(10000, sizeof(char));
	if (!s->root)
		return(-1);
	s->seek = s->root;
}

int	reset_strplus(t_strplus *s, int clear)
{
	if (clear)
		ft_bzero(s->root, ft_strlen(s->root));
	s->seek = s->root;
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

	for (int i = 0; i < 10; i++)
	{
		// printf("\n -- NEW ITTERATION --\na:<%s>\nb:<%s>\n", alice.root, bob.root);
		while (*alice.seek)
			rule_applicator(&alice.seek, &bob.seek, &g);
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