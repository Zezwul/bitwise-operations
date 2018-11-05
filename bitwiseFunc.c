#include "bitwiseFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printDecToBin(int n)
{
	int temp;
	for (int i = 31; i >= 0; i--)
	{
		temp = n >> i;
		if (temp & 1) printf("1");
		else printf("0");
	}
}

int bitwiseAdd(int first, int second)
{
	int temp;
	while (second != 0)
	{
		temp = first & second;
		first = first ^ second;
		second = temp << 1;
	}
	return first;
}

int bitwiseSub(int first, int second)
{
	return bitwiseAdd(first, bitwiseAdd(~second, 1));
}

int executeOperation(char operation, int num1, int num2)
{
	if (operation != '+' && operation != '-')
	{
		printf("Error. Unknown operator in 'printOperation' function first argument. "
				"Use only '+' or '-'.\n");
		return -1;
	}
	printf(" ");
	printDecToBin(num1);
	printf(" %d", num1);
	printf("\n");
	printf("%c", operation);
	printDecToBin(num2);
	printf(" %d", num2);
	printf("\n");
	printf(" ");
	switch(operation)
	{
		case '+':
			printDecToBin(bitwiseAdd(num1, num2));
			printf(" %d", bitwiseAdd(num1, num2));
			break;
		case '-':
			printDecToBin(bitwiseSub(num1, num2));
			printf(" %d", bitwiseSub(num1, num2));
			break;
		default:
			break;
	}
	printf(" ");
	printf("\n");
	return 0;
}
