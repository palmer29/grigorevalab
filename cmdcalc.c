#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int get_result(char * firstNum, char * operand,char * secoundNum)
{
	int intFirstNum = atoi(firstNum);
	int intSecoundNum = atoi(secoundNum);
	int result; 
	if (* operand == '+')
	{
		result = intFirstNum + intSecoundNum;
	}
	if (* operand == '-')
	{
		result = intFirstNum - intSecoundNum;
	}
	if (* operand == '*')
	{
		result = intFirstNum * intSecoundNum;
	}
	if (* operand == '%')
	{
		result = intFirstNum % intSecoundNum;
	}
	return result;
}

void print_results(int * results, const int operations, char * resultString)
{
	for (int i = 0; i < operations; ++i)
	{
		printf("Ответ №%d: %d\n", i + 1, results[i]);
	}
	printf("Результирующая строка: %s\n", resultString);
}

bool digit_check(char * str)
{
	bool checker = true;
	int size = strlen(str);
	for (int i = 0; i < size; ++i)
	{
		if (isdigit(str[i]) == 0)
		{
			checker = false;
		}
	}
	return checker;
}

bool operation_check(char * str)
{
	bool checker = true;
	if (strlen(str) == 1)
	{
		if (str[0] != '+' && str[0] != '-' && str[0] != '%'\
				&& str[0] != '*')
		{
			checker = false;
		}
	}
	else
	{
		checker = false;
	}
	return checker;
}

bool able_to_count(char * str)
{
	bool checker = true;
	int len = strlen(str);
	if (len > 10)
	{
		checker = false;
	}
	else if (len == 10)
	{
		if (strcmp(str, "214783647") == 1)
		{
			checker = false;
		}
	}
	if (strchr(str, '.') != NULL)
	{
		checker = false;
	}
	return checker;
}

int what_index_of_flag(int argc, char ** argv)
{
	int flagIndex = -1;
	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], "-k") == 0)
		{
			flagIndex = i;
		}
	}
	return flagIndex;
}

bool is_everything_okay(int argc, char ** argv)
{
	bool controlArguments = true;
	int flagChecker = 2;
	if (argc == 1)
	{
		printf("Вы ничего не ввели\n");
		controlArguments = false;
	}
	else if (what_index_of_flag(argc, argv) == -1)
	{
		printf("Вы не ввели флаг -k\n");
		controlArguments = false;
	}
	else if (what_index_of_flag(argc, argv) > (argc - 2))
	{
		printf("После флага должно быть число\n");
		controlArguments = false;
	}
	else if (what_index_of_flag(argc, argv) == 1)
	{
		printf("Вы не ввели ни одного арифметического выражения\n");
		controlArguments = false;
	}
	else if (what_index_of_flag(argc, argv) < (argc - 2))
	{
		printf("После флагa должно быть одно значение\n");
		controlArguments = false;
	}
	else if (digit_check(argv[argc - 1]) == 0)
	{
		printf("Значение после флага должно быть числом\n");
		controlArguments = false;
	}
	else 
	{
		for (int i = 1; i < argc - flagChecker; i += 3)
		{
			if (able_to_count(argv[i]) == false || able_to_count(argv[i + 2]) == false)
			{
				printf("Калькулятор умеет считать только целые ");
				printf("неотрицательные числа до 2 147 483 647 вколючительно\n");
				controlArguments = false;
			}
			else
			{
				if (digit_check(argv[i]) == 0)
				{
					printf("Аргумент №%d должен быть числом\n", i);
					controlArguments = false;
				}
				if (operation_check(argv[i + 1]) == 0)
				{
					printf("Аргумент №%d должен быть операцией (+, -, *, %%)\n", i + 1);
					controlArguments = false;
				}
				if (digit_check(argv[i + 2]) == 0)
				{
					printf("Аргумент №%d должен быть числом\n", i + 2);
					controlArguments = false;
				}
			}
			
		}
	}
	return controlArguments;
}

void getString(int operations, char * resultString, int * results, int decodingKey)
{
	for (int i = 0; i < operations; ++i)
	{
		int numChar = results[i] - decodingKey;
		resultString[i] = numChar;
	}
	resultString[operations] = 0;
}
 












