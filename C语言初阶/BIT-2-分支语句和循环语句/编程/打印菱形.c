#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int line = 0;
	scanf_s("%d", &line);
	//打印上半部分
	for (i = 0; i < line; i++)
	{
		//打印空格
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//打印下半部分  下半部分只有line-1行
	for (i = 0; i < line - 1; i++)
	{
		//打印空格
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < (line - 1 - i) * 2 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}