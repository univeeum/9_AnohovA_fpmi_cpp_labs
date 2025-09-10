#include <iostream>

std::string formatNum(int num) {
    std::string ans = std::to_string(num);
    if (num >= 10) {
        return ans;
    } else {
        ans = " " + ans;
        return ans;
    }
}

int main() {
    int n, k;

    if (!(std::cin >> n >> k) || (n < 1 || n > 7 || k < 1 || k > 99 || n > k)) {
        std::cout << "Error\n";
        std::exit(1);
    }

    int week_num = 0;

    std::cout << formatNum(week_num + 1) << " |   ";
    week_num++;

    for (int i = 0; i < n - 1; i++) {
        std::cout << "   "; 
    }
    
    for (int i = 0; i < k; i++) {
        if ((i + n - 1) % 7 == 0 && i != 0) {
            std::cout << '\n' << formatNum(++week_num) << " |   ";
        }
        std::cout << formatNum(i + 1) << ' '; 
    }
    std::cout << '\n';
}