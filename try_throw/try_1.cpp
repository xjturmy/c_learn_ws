#include <iostream>

int main(){
    int a = 2, b = 0;
    // 计算a/b
    if (b == 0) {
        std::cerr << "error: division by zero\n";
        return -1;
    } else {
        std::cout << "a / b = " << (float)a/(float)b << std::endl;
    }
    return 0;
}

