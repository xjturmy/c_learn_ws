
#include <iostream>
#include <thread>

using namespace std;

// 例二： thread执行带有引用参数的函数
template <class T>
void changevalue(T &x, T val)
{
    x = val;
}
int main()
{
    thread th[100];
    int nums[100];
    /*
    std::ref 可以包装按引用传递的值。
    std::cref 可以包装按const引用传递的值。
    */
    for (int i = 0; i < 100; i++)
    {
        th[i] = thread(changevalue<int>, ref(nums[i]), i + 1);
    }

    for (int i = 0; i < 100; i++)
    {
        th[i].join();
        cout << nums[i] << endl;
    }
    return 0;
}
