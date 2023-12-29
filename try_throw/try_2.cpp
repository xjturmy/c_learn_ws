#include <iostream>
#include <stdexcept>

int main(){
    int a = 2, b = 0;
    // 计算a/b
    if(b == 0) {
        throw std::runtime_error("error: division by zero");
    } else {
        std::cout << "a / b = " << (float)a/(float)b << std::endl;
    }
    return 0;
}


