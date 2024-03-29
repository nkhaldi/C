/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:04:35 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:04:38 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			ignore_comment(t_asm *asm_parsing, char *line)
{
	if (line[asm_parsing->symbol] == COMMENT_CHAR ||
											line[asm_parsing->symbol] == ';')
		while (line[asm_parsing->symbol])
			asm_parsing->symbol++;
}

char			*take_word(int end, char *line, int start)
{
	char	*temp;

	temp = ft_strsub(line, start, end - start);
	return (temp);
}

int				find_instruction(t_word *current)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (ft_strequ(current->name, g_op_tab[i].name))
			return (i);
		i++;
	}
	return (-1);
}

t_instruction	*init_instruction_args(void)
{
	t_instruction	*instruction_args;
	int				i;

	instruction_args = (t_instruction *)malloc(sizeof(t_instruction));
	i = -1;
	while (++i < 3)
		instruction_args->args[i] = NULL;
	return (instruction_args);
}

int				check_for_number(char *name)
{
	int i;

	i = 0;
	if (name[0] == '-')
		i++;
	while (name[i])
	{
		if (ft_isdigit(name[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
