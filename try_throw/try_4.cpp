#include <iostream>
#include <stdexcept>

int main() {
    int a, b;
    std::cout << "This is a division program. Now you should input the value of `a` and `b`.\nThen the result `a / b` will be output." << std::endl;
    while (true) {
        std::cin >> a >> b;
        try {
            if(b == 0) {
                throw std::runtime_error("error: division by zero");
            } else {
                std::cout << "a / b = " << (float)a/(float)b << std::endl;
                break;
            }
        } catch (std::runtime_error err) {
            std::cout << err.what() << std::endl;
            std::cout << "\nPlease try again." << std::endl;
        }
    }
    return 0;
}




