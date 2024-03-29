/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:03:49 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:25:22 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	cut_command(t_asm *asm_parsing, char *line)
{
	int		start;
	char	*substring;

	start = asm_parsing->symbol++;
	while (line[asm_parsing->symbol] && ft_strchr(LABEL_CHARS,
													line[asm_parsing->symbol]))
		asm_parsing->symbol++;
	substring = take_word(asm_parsing->symbol, line, start);
	add_word_to_list(asm_parsing, create_word(asm_parsing, substring, COMMAND));
}

void	cut_doubles(t_asm *asm_parsing, char *line, int start)
{
	char	*substring;
	char	*temp_join;
	char	*str;
	char	*temp;

	substring = take_word(asm_parsing->symbol, line, start);
	temp_join = substring;
	while (get_next_line(asm_parsing->fd, &line))
	{
		asm_parsing->row++;
		if (ft_strchr(line, '"'))
			break ;
		temp_join = ft_strjoin(substring, line);
		ft_strdel(&substring);
		substring = temp_join;
		ft_strdel(&line);
	}
	str = take_word(ft_strlen(line) - ft_strlen(ft_strchr(line, '"')) + 1,
																line, 0);
	temp = substring;
	substring = ft_strjoin(temp_join, str);
	ft_strdel(&temp);
	ft_strdel(&str);
	check_for_doubles(asm_parsing, line, substring);
}

void	cut_label(t_asm *asm_parsing, char *line)
{
	int		start;
	char	*substring;

	start = asm_parsing->symbol++;
	while (line[asm_parsing->symbol] && ft_strchr(LABEL_CHARS,
											line[asm_parsing->symbol]))
		asm_parsing->symbol++;
	substring = take_word(asm_parsing->symbol, line, start);
	if (ft_strlen(substring) > 1)
		add_word_to_list(asm_parsing, create_word(asm_parsing, substring,
															INDIRECT_ARG));
	else
		ft_error(asm_parsing);
}

void	cut_direct(t_asm *asm_parsing, char *line)
{
	int		start;
	char	*substring;

	start = asm_parsing->symbol++;
	if (line[asm_parsing->symbol] == LABEL_CHAR ||
									line[asm_parsing->symbol] == '-')
		asm_parsing->symbol++;
	while (line[asm_parsing->symbol] && ft_strchr(LABEL_CHARS,
											line[asm_parsing->symbol]))
		asm_parsing->symbol++;
	substring = take_word(asm_parsing->symbol, line, start);
	if (!ft_strchr(substring, ':'))
		if (ft_strchr(substring, '_'))
			error_word(asm_parsing, "Argument contains incorrect symbol");
	if (ft_strlen(substring) < 2)
		error_word(asm_parsing, "Length of argument equals 0");
	add_word_to_list(asm_parsing,
						create_word(asm_parsing, substring, DIRECT_ARG));
}
