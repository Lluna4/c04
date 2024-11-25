/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunatran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:06:27 by lunatran          #+#    #+#             */
/*   Updated: 2024/11/25 16:34:35 by lunatran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar (*str);
		str++;
	}
}

unsigned int ft_strlen(char *str)
{
	unsigned int index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return index;
}


int ft_check(char *base)
{
	char seen_chars[100];
	int index;

	index = 0;
	if (*base == '\0')
		return 0;
	if (ft_strlen(base) <= 1)
		return 0;
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return 0;
		while (seen_chars[index] != '\0')
		{
			if (seen_chars[index] == *base)
				return 0;
			index++;
		}
		seen_chars[index] = *base;
		index = 0;
		base++;
	}
	return 1;	
}

void ft_putnbr_base(int nbr, char *base)
{	
	int base_num;
	long nb;
	
	if (ft_check(base) == 0)
		return ;
	base_num = ft_strlen(base);
	nb = (long)nbr;
	if (nb < 0)
	{
		ft_putchar ('-');
		nb *= -1;
	}
	if (nb >= base_num)
	{
		ft_putnbr_base ((int)(nb / base_num), base);
		nb %= base_num;
	}
	ft_putchar (base[nb]);
}

/*
int main()
{
	ft_putnbr_base(-2147483648, "0123456789");
}*/
