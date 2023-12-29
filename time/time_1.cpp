
#include <iostream>
#include <time.h>
#include <boost/timer/timer.hpp>

using namespace std;

int main()
{

    // 第一种方法，用clock()函数，得到系统启动以后的毫秒级时间，然后除以CLOCKS_PER_SEC，就可以换成“秒”，标准c函数。
    clock_t start_time = clock();
    for (auto i = 0; i < 1000000000; ++i)
    {
        auto t = i;
    }
    clock_t end_time = clock();
    cout << "一亿次循环消耗时间： " << (double)(end_time - start_time) << "微秒" << endl;
    cout << "一亿次循环消耗时间： " << (double)(end_time - start_time) / 1000 << "毫秒" << endl;
    cout << "一亿次循环消耗时间： " << (double)(end_time - start_time) / 1000 / 1000 << "秒" << endl;

    // clock_t的最小时间间隔本身就是ms，所以输出的时间应该也是ms
}