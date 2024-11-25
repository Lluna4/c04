#include <stdio.h>
int     ft_is_numeric(char c)
{
	if (!(c >= '0' && c <= '9'))
        {
            return 0;
        }
	return 1;
}

int ft_atoi(char *str)
{
	int ret;
	char sign;
	
	ret = 0;
	sign = -1;
	while (*str == ' ')
		str++;
	while (*str == '+' || *str == '-')
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
	while (ft_is_numeric(*str) != 0)
	{
		ret += (*str - '0');
		ret *= 10;
		str++;
	}
	ret /= 10;
	if (sign == 1)
		ret *= -1;
	return ret;
}

int main()
{
	printf("%i\n", ft_atoi("    ---+12124swq"));
}

