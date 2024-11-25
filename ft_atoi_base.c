#include <stdio.h>
int     ft_is_numeric(char c, char *base)
{
	int index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return index;
		index++;
	}
	return 0;
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

int ft_atoi_base(char *str, char *base)
{
	int ret;
	char sign;
	int base_num;
	
	ret = 0;
	sign = -1;
	base_num = (int)ft_strlen(base);
	if (ft_check(base) == 0)
		return 0;
	while (*str == ' ')
		str++;
	while (ft_is_numeric(*str, base) == 0)
	{
		if (sign == -1)
		{
			if (*str == '+')
				sign = 0;
			else if (*str == '-')
				sign = 1;

		}
		str++;
	}
	while (ft_is_numeric(*str, base) != 0)
	{

		ret *= base_num;
		ret += ft_is_numeric(*str, base);
		str++;
	}
	if (sign == 1)
		ret *= -1;
	return ret;
}

int main()
{
	printf("%i\n", ft_atoi_base("FFFFFF", "01"));
}

