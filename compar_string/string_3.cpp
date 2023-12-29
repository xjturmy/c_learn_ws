#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[] = "happy";

    char str2[10] = "to";

    char *str3 = "birthday";
    // 1 不规定大小的字符数组
    printf("%s的长度为%ld, ", str1, strlen(str1));           // strlen() 输出了实际单词字节数 5
    printf("str1在内存中的长度为%ld.  \n\n", sizeof(str1)); // sizeof() 输出了实际字节数 6

    // 2 规定大小的字符数组
    printf("%s的长度为%ld, ", str2, strlen(str2));           // strlen() 输出了单词字节数 8
    printf("str2在内存中的长度为%ld.  \n\n", sizeof(str2)); // sizeof() 输出了指向char类型的指针变量在内存中的字节数 4

    // 3 指针
    printf("%s的长度为%ld,", str3, strlen(str3));           // strlen() 输出了实际单词字节数 2
    printf("str3在内存中的长度为%ld.  \n\n", sizeof(str3)); // sizeof() 输出了定义的数组的长度 10
    return 0;
}