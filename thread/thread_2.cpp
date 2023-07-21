
#include <iostream>
#include <thread>

using namespace std;

// 例二： thread执行有参数的函数
void countnumber(int id, unsigned int n)
{
    for (unsigned int i = 1; i <= n; i++)
        ;
    cout << "Thread " << id << " finished!" << endl;
}
int main()
{
    thread th[10];
    for (int i = 0; i < 10; i++)
    {
        th[i] = thread(countnumber, i, 100000000);
    }

    for (int i = 0; i < 10; i++)
    {
        th[i].join();
    }

    return 0;
}