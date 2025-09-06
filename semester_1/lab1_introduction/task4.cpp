#include <iostream>

int main() {
    
    while (true) {
        int k;
        std::cin >> k;
        
        long long result = 1;

        if(k & 1) {
            for (int i = 1; i <= k; i += 2) {
                result *= i;
            }
        }
        else{
            for (int i = 2; i <= k; i += 2) {
                result *= i;
            }
        }
        std::cout << result << '\n';
    }
}