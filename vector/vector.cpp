

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void traversal_1(vector<int> &vector_1)
{
    clock_t timeStart = clock();
    uint64_t sum = 0;
    for (vector<int>::iterator ite = vector_1.begin(); ite != vector_1.end(); ite++)
    {
        sum += *ite;
    }
    std::cout << "sum 1 is " << sum << ", use time 1 is " << (clock() - timeStart) / 1000 << "毫秒" << std::endl;
}

void traversal_2(vector<int> &vector_2)
{
    clock_t timeStart = clock();
    uint64_t sum = 0;
    for (auto it : vector_2)
    {
        sum += it;
    }
    std::cout << "sum 2 is " << sum << ", use time 2 is " << (clock() - timeStart) / 1000 << "毫秒" << std::endl;
}

void traversal_3(vector<int> &vector_3)
{
    clock_t timeStart = clock();
    uint64_t sum = 0;
    for (int i = 0; i < vector_3.size(); i++)
    {
        sum += vector_3[i];
    }
    std::cout << "sum 3 is " << sum << ", use time 3 is " << (clock() - timeStart) / 1000 << "毫秒" << std::endl;
}

void traversal_4(vector<int> &vector_3)
{
    clock_t timeStart = clock();
    uint64_t sum = 0;
    for (const auto &it : vector_3)
    {
        sum += it;
    }
    std::cout << "sum 4 is " << sum << ", use time 4 is " << (clock() - timeStart) / 1000 << "毫秒" << std::endl;
}

int main()
{

    const uint32_t loop = 10000000;
    std::vector<int32_t> vec;
    for (uint32_t i = 0; i < loop; ++i)
    {
        vec.push_back(i);
    }

    // 第一种方法，采用迭代器遍历
    traversal_1(vec);

    // 第二种方法，for 循环+auto
    traversal_2(vec);

    // 第三种方法，for 循环+[ ]
    traversal_3(vec);

    // 第四种方法，for range
    traversal_4(vec);


    /*
    结论：
    1 在linux系统下，采用下标方式最快（第三种），采用for range (第四种）,迭代器最慢（第一种方法）
    2 测试在ubuntu-debug 和 ubuntu-release的差异
    */
}