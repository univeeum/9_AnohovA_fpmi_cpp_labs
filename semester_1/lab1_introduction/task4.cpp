#include <iostream>

int main() {
    int k;

    if (!(std::cin >> k) || k < 0) {
        std::cout << "Error\n";
        std::exit(1);
    }

    long long result = 1;
    if(k & 1) {
        for (int i = 1; i <= k; i += 2) {
            result *= i;
        }
    } else{
        for (int i = 2; i <= k; i += 2) {
            result *= i;
        }
    }
    std::cout << result << '\n';
}