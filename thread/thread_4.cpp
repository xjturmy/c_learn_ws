
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// 例四： 多线程对相同函数操作,std::mutex
int n = 0;
mutex mtx;
void count10000()
{
    for (int i = 1; i <= 10000; i++)
    {
        /*
            采用mutex加锁，能够避免参数调用出错
            加锁之后需要及时的解锁
        */
        mtx.lock();
        n++;
        mtx.unlock();
    }
}
int main()
{
    thread th[100];
    // 这里偷了一下懒，用了c++11的foreach结构

    /*
        多个线程同时操作一个变量，会出错，
        需要用std::atomic和std::mutex加锁
    */
    for (thread &x : th)
    {
        x = thread(count10000);
    }

    for (thread &x : th)
    {
        x.join();
    }

    cout << n << endl;
    return 0;
}
