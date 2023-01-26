#include "stack_manager.h"

// 숫자가 아닌 문자 처리
void	input_error(int argc, char *argv[], t_stack *a, int *digit_len)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			add_split_digit(argv, a, i, digit_len);
		else
		{
			if (!is_str_digit(argv[i]))
			{
				printf("Error\n");
				exit(1);
			}
			add_back(a, ft_atoi(argv[i]), i - 1);
			(*digit_len)++;
		}
		i++;
	}
}

void	add_split_digit(char *argv[], t_stack *a, int i, int *digit_len)
{
	int		j;
	char	**split_input;

	j = 0;
	split_input = 0;
	split_input = ft_split(argv[i], ' ');
	if (split_input[0] == 0)
	{
		printf("Error\n");
		exit(1);
	}
	while (split_input[j])
	{
		if (!is_str_digit(split_input[j]))
		{
			printf("Error\n");
			exit(1);
		}
		add_back(a, ft_atoi(split_input[j]), i - 1);
		(*digit_len)++;
		j++;
	}
	free_split(split_input);
}

void	add_arr_digit(char *argv[], int i, int *index, int *arr)
{
	int		j;
	char	**split_input;

	j = 0;
	split_input = 0;
	split_input = ft_split(argv[i], ' ');
	while (split_input[j])
	{
		arr[(*index)] = ft_atoi(split_input[j]);
		(*index)++;
		j++;
	}
	free_split(split_input);
}

int	is_str_digit(const char *s)
{
	// +, -, 숫자만
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while(s[i] >= '0' && s[i] <= '9')
	{
		if(!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++; 
	}
	if(!(s[i] >= '0' && s[i] <= '9') && s[i] != 0)
		return (0);
	return (1);
}
