/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:14:48 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/26 18:17:40 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putpercent_c(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int		ft_putconv(char *flags, va_list *args)
{
	if (flags[ft_strlen(flags) - 1] == 's')
		return (ft_putstr_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'c')
		return (ft_putchar_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'd')
		return (ft_putd_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'i')
		return (ft_putd_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'u')
		return (ft_putu_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'x')
		return (ft_putxmin_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'X')
		return (ft_putxmaj_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == 'p')
		return (ft_putptr_c(flags, args));
	if (flags[ft_strlen(flags) - 1] == '%')
		return (ft_putpercent_c());
	return (0);
}

int		ft_printf(const	char *src, ...)
{
	va_list	args;
	char	**flags;
	int		cpt;

	va_start(args, src);
	flags = ft_split_flags(src);
	cpt = ft_while_printf(src, flags, &args);
	ft_free_tab(flags);
	va_end(args);
	if (cpt < 0)
		return (0);
	return (cpt);
}
