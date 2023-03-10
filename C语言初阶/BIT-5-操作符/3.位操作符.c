#include<stdio.h>
/*
位操作符(二进位)有：
& 按位与   一一得一
| 按位或   有一得一
^ 按位异或   相同为0，相异为1
注：他们的操作数必须是整数。
*/

//1.按位与
/*
int main()
{
	int a = 3;
	int b = -5;
	int c = a & b;
	printf("%d\n", c);   //3
	//10000000000000000000000000000101  -5的原码
	//11111111111111111111111111111010  -5的反码
	//11111111111111111111111111111011  -5的补码
	//00000000000000000000000000000011  3的原码=补码
	//00000000000000000000000000000011  按位&的结果3
	return 0;
}
*/


//2.按位或
/*
int main()
{
	int a = 3;
	int b = -5;
	int c = a | b;
	printf("%d\n", c);   //-5
	//10000000000000000000000000000101  -5的原码
	//11111111111111111111111111111010  -5的反码
	//11111111111111111111111111111011  -5的补码
	//00000000000000000000000000000011  3的原码=补码
	//11111111111111111111111111111011  按位|的结果3
	//11111111111111111111111111111010  -1的反码
	//10000000000000000000000000000101  原码为-5
	return 0;
}
*/


//3.按位异或
/*
int main()
{
	int a = 3;
	int b = -5;
	int c = a ^ b;
	printf("%d\n", c);   //-8
	//10000000000000000000000000000101  -5的原码
	//11111111111111111111111111111010  -5的反码
	//11111111111111111111111111111011  -5的补码
	//00000000000000000000000000000011  3的原码=补码
	//11111111111111111111111111111000  按位^的结果3
	//11111111111111111111111111110111
	//10000000000000000000000000001000  结果-8

	return 0;
}
*/



/*
int main()
{
	int num1 = 1;    //00000001
	int num2 = 2;    //00000010
	num1 & num2;     //00000000
	num1 | num2;     //00000011
	num1^ num2;      //00000011
	return 0;
}
*/


//4.一道变态的面试题：不能创建临时变量（第三个变量），实现两个数的交换。
/*
int main()      //当a和b的值相加时 值可能会溢出
{
	int a = 3;
	int b = 5;
	a = a + b;
	b = a - b;    //(a+b)-b   b=a
	a = a - b;    //a-(a-b)   a=b
	return 0;
}
*/

//3^3=0
//5^5=0  相同两个数异或的值为0
//3^5=6  
//3^5^5  5^5=0   3^0=3
/*
int main()      //这种交换方式效率比较慢  不容易读
{
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = a ^ b;  //(a^b)^b = a
	a = a ^ b;  //a^(a^b) = b
	printf("a = %d b = %d\n", a, b);  //20 10
	return 0;
}
*/


//5.练习：编写代码实现：求一个整数存储在内存中的二进制中1的个数。
//方法1 取余法  效率慢
/*
int main()
{
	int num = 10;
	int count = 0;
	while (num)
	{
		if (num % 2 == 1)   //
			count++;
		num = num / 2;
	}
	printf("二进制中1的个数=%d\n", count);
	return 0;
}
*/

//方法2  
//1<<i   
/*
int main()
{
	int num = -1; //32个1
	int i = 0;
	int count = 0;//计数
	for (i = 0; i < 32; i++)
	{
		if (num & (1 << i))
			count++;
		//11111111111111111111111111111111  num
		//00000000000000000000000000000001  1左移0-31次
		//11111111111111111111111111111111   &后32次
	}
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}
//思考还能不能更加优化，这里必须循环32次的。
*/


//方法3  效率最高，难以想到
/*
int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//计数
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}
*/

//这种方式是不是很好？达到了优化的效果，但是难以想到。
