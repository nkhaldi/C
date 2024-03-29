/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:09 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:05:11 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_word	*create_word(t_asm *asm_parsing, char *name, int type)
{
	t_word	*new_word;

	if ((new_word = (t_word *)malloc(sizeof(t_word))) == NULL)
		ft_arg_error("Can't allocate memory");
	new_word->name = name;
	new_word->word_type = type;
	new_word->row = asm_parsing->row;
	new_word->next = NULL;
	return (new_word);
}

void	add_word_to_list(t_asm *asm_parsing, t_word *new_word)
{
	t_word	*temp;

	if (asm_parsing->words == NULL)
		asm_parsing->words = new_word;
	else
	{
		temp = asm_parsing->words;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_word;
	}
}
