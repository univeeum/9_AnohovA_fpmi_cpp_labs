#include <iostream>

int main() {
    int n;
    std::cin >> n;

    double ans = 0;
    double minval, maxval; 

    for (int i = 0; i < n; i++) {
        double num; std::cin >> num;
        if(i == 0) {
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