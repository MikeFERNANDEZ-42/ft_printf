/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:31:32 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/26 18:15:11 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len_src(const char *src)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			while (src[i] == '%' || (ft_is_conv(src[i]) == 1))
				i++;
		}
		i++;
		cpt++;
	}
	return (cpt);
}

void	ft_put_printf(const char *src, int *i)
{
	while (src[*i] != '%' && (src[*i]))
	{
		ft_putchar_fd(src[*i], 1);
		*i = *i + 1;
	}
}

int		ft_nb_flags(char **flags)
{
	int j;

	j = 0;
	while (flags[j])
		j++;
	return (j);
}

int		ft_while_printf(const char *src, char **flags, va_list *args)
{
	int cpt;
	int i;
	int j;

	cpt = ft_len_src(src);
	i = 0;
	j = 0;
	while (i < ft_strlen(src))
	{
		ft_put_printf(src, &i);
		if (j < ft_nb_flags(flags))
		{
			if (ft_flags_valid(flags[j]) == -1)
				return (-1);
			cpt += ft_putconv(flags[j], args);
			i += ft_strlen(flags[j]) - 1;
			j++;
		}
		i++;
	}
	return (cpt);
}
