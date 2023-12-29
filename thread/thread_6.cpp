
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// 例二： thread执行带有引用参数的函数
template <class T>
void changevalue(T &x, T val)
{
    x = val;
}
void lineFitThread(const unsigned int start_index,
                   const unsigned int end_index,
                   int *nums,
                   std::mutex *lines_mutex)
{
    lines_mutex->lock();
    for (int i = start_index; i < end_index; i++)
    {
        nums[i] = i;
    }
    lines_mutex->unlock();
}
int main()
{
    std::mutex line_mutex; // 采用多线程的方式进行直线的拟合

    thread th[100];
    int nums[100];
    /*
    std::ref 可以包装按引用传递的值。
    std::cref 可以包装按const引用传递的值。
    */
    int threads = 5;
    int segments = 20;
    vector<std::thread> thread_vec(threads);
    vector<int> list_temp[100];
    for (int i = 0; i < threads; i++)
    {
        // 设置每个线程索引的起点和终点
        const unsigned int start_index = segments / threads * i;
        const unsigned int end_index = segments / threads * (i + 1);

        // 每个线程输入起点和终点
        thread_vec[i] = std::thread(lineFitThread, start_index, end_index, nums, &line_mutex);
    }

    for (int i = 0; i < threads; i++)
    {
        th[i].join();
    }

    for (int i = 0; i < 100; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}
