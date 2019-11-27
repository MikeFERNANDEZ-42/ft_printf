/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:41:01 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/26 18:09:35 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_flags_valid(char *flags)
{
	int		i;
	int		ret;
	char	*conv;

	if (!flags)
		return (-1);
	conv = ft_strdup("csdiuxXp%%");
	i = 0;
	ret = -1;
	while (conv[i])
	{
		if (flags[ft_strlen(flags) - 1] == conv[i])
			ret = 1;
		i++;
	}
	free(conv);
	return (ret);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
	}
}

int		ft_is_conv(char c)
{
	char	*conv;
	int		i;

	conv = ft_strdup("cspdiuxX-0123456789.*");
	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
		{
			free(conv);
			return (1);
		}
		i++;
	}
	free(conv);
	return (0);
}

char	*ft_find_flags(const char *str)
{
	int		i;
	int		j;
	char	*cpy;

	cpy = ft_calloc((strlen(str) * 2), sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((i != 0) && (str[i - 1] == '%'))
		{
			cpy[j++] = str[i - 1];
			if (str[i] == '%')
				cpy[j++] = str[i++];
			else
			{
				while ((ft_is_conv(str[i]) == 1) && str[i])
					cpy[j++] = str[i++];
			}
			cpy[j++] = ',';
		}
		i++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char	**ft_split_flags(const char *str)
{
	char	**tab;
	char	*s;
	int		i;

	i = 0;
	s = ft_find_flags(str);
	tab = ft_split(s, ',');
	ft_strdel(&s);
	return (tab);
}
