#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "abc";
    int ret = strcmp(arr1, arr2);
    if (ret > 0)
    {
        printf("arr1>arr2 \n");
    }
    else if (ret < 0)
    {
        printf("arr1<arr2 \n");
    }
    else
    {
        printf("arr1=arr2 \n");
    }
    return 0;
}