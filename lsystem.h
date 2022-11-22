/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsystem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:00 by marvin            #+#    #+#             */
/*   Updated: 2022/11/22 13:39:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSYSTEM
# define LSYSTEM

# include <stdio.h>

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

typedef struct s_rule
{
	char	*initial;
	char	*result;
} t_rule;

typedef struct s_genus
{
	char	*vars;
	int		nv;
	char	*consts;
	int		nc;
	char	*axiom;
	t_rule	**rules;
} t_genus;



#endif /*lsystem*/