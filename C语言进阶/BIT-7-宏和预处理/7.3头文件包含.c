//1.头文件被包含的方式：
/* 本地文件包含" "
查找策略：先在源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置查找头文件。
如果找不到就提示编译错误。 */
/* 
#include"add.h"
int main()
{
    printf("hehe\n");
    return 0;
} */

//库文件包含 < >
/* 
查找头文件直接去标准路径下去查找，如果找不到就提示编译错误。
这样是不是可以说，对于库文件也可以使用 " " 的形式包含？
答案是肯定的，可以。
但是这样做查找的效率就低些，当然这样也不容易区分是库文件还是本地文件了。 */


//2.嵌套文件包含
#include"add.h"
#include"add.h"
#include"add.h"
#include"add.h"
#include"add.h"
int main()
{

    return 0;
}


//每个头文件的开头写 - 就可以避免头文件的重复引入。
/* #ifndef __TEST_H__
#define __TEST_H__
//头文件的内容
#endif   //__TEST_H__

#pragma once - 也可以直接写这一行代替上面的内容
 */