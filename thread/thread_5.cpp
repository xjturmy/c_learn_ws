
#include <iostream>
#include <thread>
// #include <mutex>
#include <atomic>
using namespace std;

// 例五： 多线程对相同函数操作,std::atomic
atomic<int> n(0);
void count10000()
{
    for (int i = 1; i <= 10000; i++)
    {
        n++;
    }
}
int main()
{
    thread th[100];
    for (thread &x : th)
        x = thread(count10000);
    for (thread &x : th)
        x.join();
    cout << n << endl;
    return 0;
}

/* 存在原子变量无法赋值的错误
https://blog.csdn.net/qq_34999565/article/details/119151319?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-119151319-blog-121888550.235%5Ev38%5Epc_relevant_default_base&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-119151319-blog-121888550.235%5Ev38%5Epc_relevant_default_base&utm_relevant_index=1
*/