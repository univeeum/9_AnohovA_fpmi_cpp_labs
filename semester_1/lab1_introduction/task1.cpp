#include <iostream>

int main () {
    int a, b, d;

    if (!(std::cin >> a >> b >> d) || d == 0) {
        std::cout << "Error\n";
        std::exit(1);
    }
    
    if (d > 0) {
        if (a > b) std::swap(a, b);

        for (int i = a; i <= b; i += d) {
            if (i % 3 == 0) 
                std::cout << i << ' '; 
        }
    } else {
        if (a < b) std::swap(a, b);

        for (int i = a; i >= b; i += d) {
            if (i % 3 == 0) 
                std::cout << i << ' '; 
        }
    }
    std::cout << '\n';
}