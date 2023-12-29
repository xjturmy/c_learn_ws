#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    //可以测试简单的读写文件
    ofstream out("/home/rmy/03_learning_materials/c_learn_ws/string/a.txt", ios::out);

    if (out)
    {
        out << "This is a line.\n";
        out << "This is another line.\n";
    }
    out.close();
    return 0;
}