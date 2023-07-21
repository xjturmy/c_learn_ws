
#include <iostream>
#include <thread>

using namespace std;

// 例一：thread的基本使用
void doit()
{
    cout << "World!" << endl;
}

int main()
{
    thread a([]
             { cout << "Hello, " << flush; }),
        b(doit);
    a.join();
    b.join();
    return 0;
}