#include <iostream>
#include "boost/timer.hpp"
using namespace std;

int main()
{
    boost::timer t;

    std::cout << "每秒时钟数：" << CLOCKS_PER_SEC << std::endl;
    std::cout << "可度量的最大时间：" << t.elapsed_max() / 3600 / 1000 / 24 << "天" << std::endl;
    std::cout << "可度量的最大时间：" << t.elapsed_max() / 3600 / 1000 << "小时" << std::endl;
    std::cout << "可度量的最小时间：" << t.elapsed_min() << "秒" << std::endl;

    t.restart(); // 重新计时
    for (auto i = 0; i < 1000000000; ++i)
    {
        auto t = i;
    }
    cout << "一亿次循环消耗时间： " << (double)t.elapsed() * CLOCKS_PER_SEC << "微秒" << endl;
    cout << "一亿次循环消耗时间： " << (double)t.elapsed() * CLOCKS_PER_SEC / 1000 << "毫秒" << endl;
    cout << "一亿次循环消耗时间： " << (double)t.elapsed() << "秒" << endl;
    getchar();
    return 0;

    // 测试记录，采用boost：:timer在window上的最小时间间隔是1000微妙，但是在linux上的最小时间间隔是1微妙
}
