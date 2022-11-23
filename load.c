/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:44:55 by znichola          #+#    #+#             */
/*   Updated: 2022/11/22 14:44:55 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsystem.h"

int	init_strplus(t_strplus *s)
{
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

static int	ft_countwords(char const *s, char const c)
{
	int		count;
	int		flag;
	int		old_flag;

	flag = -1;
	count = 0;
	while (*s)
	{
		old_flag = flag;
		if (*s == c)
			flag = 0;
		else
			flag = 1;
		if (old_flag != flag && flag == 1)
			count++;
		s++;
	}
	return (count);
}

// format is A AB B A
//		(A->AB),(B->A)
int	get_rules(t_genus *g, char *r)
{
	int	i;

	g->nr = ft_countwords(r, ' ');
	if (g->nr % 2)
		return (ERROR);
	g->nr = g->nr / 2;
	g->rules = (t_rule **)malloc(sizeof(t_rule *) * g->nr + 1);
	i = -1;
	while (i++ < g->nr - 1)
	{
		g->rules[i] = (t_rule *)malloc(sizeof(t_rule));
		if (!g->rules[i])
			return (ERROR); // TODO do the freeing of the other bits
		while (*r == ' ')
			r++;
		g->rules[i]->initial = r;
		while (*r != ' ')
			r++;
		*r++ = '\0';
		while (*r == ' ')
			r++;
		g->rules[i]->result = r;
		while (*r != ' ')
			r++;
		*r++ = '\0';
	}
	g->rules[i] = NULL;
	return (SUCCESS);
}

int	init_genus(t_genus *g, char **input)
{
	g->vars = input[0];
	g->nv = ft_strlen(input[0]);
	g->consts = input[1];
	g->nc = ft_strlen(input[1]);
	g->axiom = input[2];
	// dump_genus(g);
	if (get_rules(g, input[3]))
		return (ERROR);
}