#include <iostream>

int main() {
    int a, b;
    std::cout << "This is a division program. Now you should input the value of `a` and `b`.\nThen the result `a / b` will be output." << std::endl;
    while (true) {
        std::cin >> a >> b;
        if (b == 0) {
            std::cerr << "error: division by zero\n";
            std::cout << "\nPlease try again." << std::endl;
        } else {
            std::cout << "a / b = " << (float)a/(float)b << std::endl;
            break;
        }
    }
    return 0;
}



