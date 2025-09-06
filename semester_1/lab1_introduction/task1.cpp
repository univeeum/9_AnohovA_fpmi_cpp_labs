#include <iostream>

int main() {
    int a, b, d;
    std::cin >> a >> b >> d;
    for(int i = a; i <= b; i+= d) {
        if (i % 3 == 0) 
            std::cout << i << ' '; 
    }
}