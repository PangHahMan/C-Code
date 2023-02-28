#include<stdio.h>
#include<math.h>
int Judge(int i)
{
	int j = 0;
	for (j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int i = 0;
	int x = 0;
	scanf("%d", &i);
	x = Judge(i);
	if (x == 1)
	{
	     printf("%d是素数 ", i);
	}
	else
	{
		printf("%d不是素数 ", i);
	}
	return 0;
}