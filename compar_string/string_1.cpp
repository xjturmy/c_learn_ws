#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "abc";

    std::cout << "arr1 地址: " << &arr1 << ", arr2 地址: " << &arr2 << endl;

    // 一种比较两个字符串大小的方法
    int i = 0;
    int n1 = strlen(arr1);//得到字符串长度
    int n2 = strlen(arr2);
    while (n1 && n2)
    {
        if (arr1[i] < arr2[i])
        {
            printf("arr1<arr2\n");
            break;
        }
        else if (arr1[i] > arr2[i])
        {
            printf("arr1>arr2\n");
            break;
        }
        n1--;
        n2--;
        i++;
    }

    if ((n1 == 0) && (n2 == 0))
    {
        printf("arr1=arr2\n");
    }
    else if (n1 == 0)
    {
        printf("arr1<arr2");
    }
    else if (n2 == 0)
    {
        printf("arr1>arr2");
    }

    return 0;
}