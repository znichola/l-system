/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:17:19 by znichola          #+#    #+#             */
/*   Updated: 2022/11/22 17:17:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lsystem.h"

int	dump_rule(t_rule *r)
{
	printf("(%s->%s)", r->initial, r->result);
	return (SUCCESS);
}

int	dump_genus(t_genus *g)
{
	int	i;

	printf("\nvars	<%s>	n:%d\n", g->vars, g->nv);
	printf("consts	<%s>	n:%d\n", g->consts, g->nc);
	printf("axiom	<%s>\n", g->axiom);
	i = 0;
	while (g->rules[i])
	{
		dump_rule(g->rules[i++]);
		printf(" ");
	}
	printf("\n");
	return (SUCCESS);
}