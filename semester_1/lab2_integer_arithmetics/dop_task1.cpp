#include <iostream>

using namespace std;

void TryRead(int& number) {
    if (!(std::cin >> number)) {
        std::cout << "Fail on reading the number." << std::endl;
        exit(0);
    }
}

bool IsNotNegative(int number) {
    return abs(number) == number;
}

int main() {
    int number;

    std::cout << "Enter the number: ";
    TryRead(number);

    bool std_non_negative_check = (number >= 0);

    if (IsNotNegative(number) == std_non_negative_check) {
        std::cout << "Try again..." << std::endl;
    } else {
        std::cout << "Shit, you broke my program :(" << std::endl;
        exit(1);
    }

    return 0;
}

/*

Взлом программы:

Enter the number: -2147483648
Shit, you broke my program :(

Пояснение: 
Диапазон значений у int от −2 147 483 648 до 2 147 483 647
Тогда если в функции IsNotNegative мы выполним abs(−2 147 483 648) то оно должно стать 2 147 483 648, 
но т.к. макс значение int на единицу меньше, будет переполнение типа и соответственно ошибка.

*/