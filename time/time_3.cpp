
#include <iostream>
#include <thread>
#include <ctime>
#include <unistd.h>
#include <chrono>
using namespace std;
#include <time.h>
#include <boost/timer/timer.hpp>
using namespace std::chrono;
typedef unsigned long DWORD;
void init()
{
    int count = 0;
    for (int i = 0; i < 100000; i++)
    {
        count = count + 1;
    }
    return;
}

unsigned long GetTickCount()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}
//输出指定的时间间隔

int main()
{

    // thread b(doit);
    // b.join();
    // 第一种方法，用clock()函数，得到系统启动以后的毫秒级时间，然后除以CLOCKS_PER_SEC，就可以换成“秒”，标准c函数。
    clock_t start_time = clock();
    init();
    clock_t end_time = clock();
    cout << "第一种方法运行时间： " << (double)(end_time - start_time) << "ms" << endl;

    // 第二种方法，timer类可以测量时间的流逝，是小型计时器，提供毫秒级别的计时精度。特别注意:这个函数并非实时发送，而是由系统每18ms发送一次，因此其最小精度为18ms。当需要有小于18ms的精度计算时，应使用StopWatch方法进行。
    DWORD Start = GetTickCount();
    init();
    DWORD End = GetTickCount();                                      // 显示运行时间间隔为1000ms
    cout << "第二种方法运行时间：" << (End - Start) << endl; // 输出已流失的时间

    struct timespec time1 = {0, 0};
    clock_gettime(CLOCK_REALTIME, &time1);
    printf("CLOCK_REALTIME: %ld, %ld\n", time1.tv_sec, time1.tv_nsec);

    auto start = high_resolution_clock::now();
    // 休眠1秒钟
    cout << "start sleeping..." << endl;
    std::this_thread::sleep_for(seconds(2));
    cout << "sleeping finished." << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "duration: " << duration.count() << "ms" << endl;
}