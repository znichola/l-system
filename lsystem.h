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
# include <stdlib.h>


# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

typedef struct s_strplus
{
	char	*root;
	char	*seek;
} t_strplus;

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
	int		nr;
} t_genus;

// load
int	init_strplus(t_strplus *s);
int	reset_strplus(t_strplus *s, int clear);
int	init_genus(t_genus *g, char **input);

// utils
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

// debug
int	dump_rule(t_rule *r);
int	dump_genus(t_genus *g);
void	ft_bzero(void *s, size_t n);

#endif /*lsystem*/