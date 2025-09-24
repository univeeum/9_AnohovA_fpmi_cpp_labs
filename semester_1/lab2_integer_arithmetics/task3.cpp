#include <iostream>
#include <cmath>

bool OnlyNumbers(std::string s) {
    for (char now : s) {
        if (!(now >= '0' && now <= '9')) {
            return false;
        }
    }
    return true;
}

int main () {
    
    std::string num;
    std::cout << "Enter a natural number:\n";

    if (!(std::cin >> num)) {
        std::cout << "Error\n";
        return 1;
    }

    if (num.empty() || !OnlyNumbers(num) || (num.size() > 1 && num[0] == '0')) {
        std::cout << "Error\n";
        return 1;
    }

    char min_digit = '9';
    for (char c : num) {
        if (c != '0' && c < min_digit) {
            min_digit = c;
        }
    }
    std::string result;
    result += min_digit;
    result += num;
    result += min_digit;
    
    std::cout << result << '\n';
}