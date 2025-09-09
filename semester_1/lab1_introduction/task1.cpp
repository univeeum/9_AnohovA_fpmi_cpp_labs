#include <iostream>

int main() {
    int a, b, d;
    std::cin >> a >> b >> d;

    if (d == 0) {
        std::cout << "Error\n";
    }

    for(int i = a; i <= b; i+= d) {
        if (i % 3 == 0) 
            std::cout << i << ' '; 
    }
    std::cout << '\n';
}