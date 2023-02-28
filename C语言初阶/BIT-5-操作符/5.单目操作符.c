#include<stdio.h>
/*
!           逻辑反操作
-           负值
+           正值
&           取地址
sizeof      操作数的类型长度（以字节为单位）
~           对一个数的二进制按位取反
--          前置、后置--
++          前置、后置++
*           间接访问操作符(解引用操作符)
(类型)      强制类型转换
*/



/*  1. ！逻辑反操作
int main()
{
	int flag = 0;
	if (!flag)
	{
		printf("hehe\n");
	}
	return 0;
}
*/


/* 2.  &取地址和*解引用操作符
int main()
{
	int a = 10;
	char c = 0;
	printf("%p\n", &a);
	printf("%p\n", &c);

	int* pa = &a;
	*pa = 20;   //将pa地址的值改成20
	printf("%d", a);  //20
	return 0;
}
*/


//int main()
//{
//	int arr[10];
//	&arr;  //取出数组的地址
//	//还可以对函数取地址
//	return 0;
//}


//int main()
//{
//	*(int*)0x0012f40 = 100;    //错误写法，野指针
//	return 0;
//}


 
/*
3. 关键字sizeof  操作数的类型长度（以字节为单位）
int main()
{
	int a = 10;
	int* p;
	int arr[10];
	printf("%zu\n",sizeof(a));   //4
	printf("%zu\n",sizeof(p));    //8  64位地址8位   32位地址4个字节
	printf("%zu\n",sizeof(arr));   //40
	printf("%zu\n",sizeof(arr[10]));    //4
	printf("%zu\n",sizeof a);    //这样写对吗？  对的
	//printf("%zu\n",sizeof int);    这样写对吗？ 不行
	printf("%zu\n",sizeof (int));    //这样写对吗？行
	return 0;
}
*/


/*
int main()
{
	short s = 10;
	int a = 2;
	printf("%zu\n", sizeof(s = a + 5));  //截断  4个字节放到两个字节的数字   4个字节截断成2个字节
	//由short决定  结果为2
	printf("%d\n", s); //10    ☆sizeof内部放的表达式不会计算
	s = a + 5;
	printf("%d", s); //7
	return 0;
}
*/


/*4. sizeof和数组

void test1(int arr[])   //int *arr
{
	printf("%zu\n", sizeof(arr));  //8
}
void test2(char ch[])   //char *ch
{
	printf("%zu\n", sizeof(ch));  //8
}

int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%zu\n", sizeof(arr));  //40
	printf("%zu\n", sizeof(ch));   //10
	test1(arr);
	test2(ch);
	return 0;
}
*/


/*
数组名：
数组名是数组首元素的地址
但是有两个例外：
1.sizeof(数组名)，数组名表示整个数组，sizeof计算的是整个数组的大小
2.&数组名，数组名表示整个数组，&数组名取出的是整个数组的地址
*/


//5. ~ 对一个数的二进制按位取反
/*
int main()
{
	int a = 0;
	//000000000000000000000000000000000000000000000000
	//111111111111111111111111111111111111111111111111 补码
	//111111111111111111111111111111111111111111111110  -1
	//100000000000000000000000000000000000000000000001  取反
	printf("%d\n", ~a);  //-1
	return 0;
}
*/

/*
int main()
{
	int a = 10;
	int n = 0;
	scanf_s("%d", &n);   //5
	//把a的第n的位置为1
	a = a | (1 << n-1);
	printf("a=%d\n", a);
	//把a的第n的位置为0
	a = a & ~(1 << (n - 1));
	printf("a=%d\n", a);
	//000000000000000000000000000000000000000000001010  //将第n位改成1
	//000000000000000000000000000000000000000000000100  1<<2  1<<(n-1)

	//000000000000000000000000000000000000000000001110   14
	//000000000000000000000000000000000000000000011010   26  n=5

	//000000000000000000000000000000000000000000011010   n=5 第5的位置变成0
	//111111111111111111111111111111111111111111101111   &这个的数字即可
	//000000000000000000000000000000000000000000010000   上面的数字由这个取反得到，1<<(n-1)
	//000000000000000000000000000000000000000000001010
	return 0;
}
*/


//6.  ++  --
/*
int main()
{
	int b1 = 4;
	int c1 = 4;
	int d1 = 4;
	int e1 = 4;
	int b = ++b1;   //前置++，先++，后使用  b==5    b1=b1+1; b=b1;
	int c = c1++;     //后置++，先使用，再++  c==4   c=c1;   c1=c1+1;
	int d = --d1;
	int e = e1--;
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	return 0;
}
*/


//7.强制类型转换
/*
int main()
{
	int a = (int)3.14;
	return 0;
}
*/