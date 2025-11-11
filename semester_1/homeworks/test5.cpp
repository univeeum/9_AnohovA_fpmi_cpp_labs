#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

inline std::string LongSum(const std::string& a, const std::string& b) {
    std::string result;
    auto i = static_cast<int64_t>(a.size() - 1);
    auto j = static_cast<int64_t>(b.size() - 1);
    int32_t rem = 0;

    while (i >= 0 || j >= 0) {
        const uint8_t a_num = i >= 0 ? a[i] - '0' : 0;
        const uint8_t b_num = j >= 0 ? b[j] - '0' : 0;
        const uint8_t sum = a_num + b_num + rem;

        const auto res_num = static_cast<char>('0' + (sum % 10));

        result.push_back(res_num);
        rem = sum / 10;
        --i;
        --j;
    }

    if (rem != 0) {
        result.push_back(static_cast<char>(rem + '0'));
    }

    std::reverse(result.begin(), result.end());
    return result;
}

bool IsValidNumber(const std::string& num) {
    if (num.empty()) {
        return false;
    }

    for (char c : num) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        std::string num1, num2;
        std::cout << "Enter first number\n";
        std::getline(std::cin, num1);

        std::cout << "Enter second number\n";
        std::getline(std::cin, num2);

        if (!IsValidNumber(num1) || !IsValidNumber(num2)) {
            std::cout << "Error! Please enter positive integers only.\n";
            return 1;
        }

        std::string result = LongSum(num1, num2);

        std::cout << "\nCalculation Result\n";
        std::cout << result << '\n';

    } catch (...) {
        std::cout << "Error :(";
        return 1;
    }

    return 0;
}