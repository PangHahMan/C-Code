//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
/*
思路：
1. 从上述表达式可以分析出
   a. 该表达式主要由100项，基数项为正，偶数项为负
2. 设置一个循环从1~100，给出表达式中的每一项：1.0/i, 注意此处不能使用1，否则结果全部为0
	然后使用flag标记控制奇偶项，奇数项为正，偶数项为负
	然后将所有的项相加即可
*/
#include <stdio.h>
int  main()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}