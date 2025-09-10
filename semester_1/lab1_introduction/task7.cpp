#include <iostream>

int main() {
    int n;
    
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Error\n";
        std::exit(1);
    }

    double ans = 0;
    double minval, maxval; 

    for (int i = 0; i < n; i++) {
        double num; 
        if (!(std::cin >> num)) {
            std::cout << "Error\n";
            std::exit(1);
        }

        if (i == 0) {
            maxval = num; 
            minval = num;
        }
        
        minval = std::min(minval, num);
        maxval = std::max(maxval, num);
        ans += num; 
    }
    ans /= n;

    std::cout << ans << ' ' << minval << ' ' << maxval << '\n';
}