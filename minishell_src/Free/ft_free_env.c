/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:15:27 by ngriveau          #+#    #+#             */
/*   Updated: 2023/03/27 12:28:01 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_Include/minishell.h"

void	ft_free_env(t_data *data)
{
	t_env	*tmp;
	t_env	*adresse;

	ft_free_dchar(data->just_export);
	tmp = &data->env;
	free(tmp->key);
	free(tmp->value);
	tmp = tmp->next;
	while (tmp)
	{
		free(tmp->key);
		free(tmp->value);
		adresse = tmp->next;
		free(tmp);
		tmp = adresse;
	}
}
