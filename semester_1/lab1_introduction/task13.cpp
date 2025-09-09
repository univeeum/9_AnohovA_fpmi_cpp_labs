#include <iostream>

int main() {

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Error\n";
        return 0;
    }

    long long prev1 = 0, prev2 = 1;
    if (n >= 1) {
        std::cout << prev1 << ' ';
    }
    if (n >= 2) {
        std::cout << prev2 << ' ';
    }

    for (int i = 2; i < n; i++) {
        long long current = prev1 + prev2;
        std::cout << current << ' ';
        prev1 = prev2;
        prev2 = current;
    }

    std::cout << '\n';
}