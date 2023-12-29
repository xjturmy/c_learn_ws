#include <iostream>

using namespace std;
int main()
{
    string in_str;
    getline(std::cin, in_str); // 输入带空格的字符串
    cout << "get string is " << in_str << endl;

    string in_str_2;
    std::cin >> in_str_2; // 从第一个真正的字符开始，到下一处空白停止
    cout << "get string 2 is " << in_str_2 << endl;

    string in_str_3 = "hello world";
    string in_str_4;
    in_str_4 = in_str_3;
    cout << "get string 4 is " << in_str_4 << endl;
}