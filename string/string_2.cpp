#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    int a;
    ifstream file("/home/rmy/03_learning_materials/c_learn_ws/string/a.txt");
    file >> a;
    cout << "状态值为：" << file.rdstate() << endl;
    if (file.good())
    {
        cout << " 输入数据的类型正确，无错误!" << endl;
    }

    if (file.fail())
    {
        cout << " 输入数据类型错误，非致命错误，可清除输入缓冲区挽回!" << endl;
    }
}