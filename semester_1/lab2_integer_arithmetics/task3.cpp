#include <iostream>

int main () {
    std::string s;
    if (!(std::cin >> s)) {
        std::cout << "Error\n";
        std::exit(1);
    }
    
    std::cout << '1' << s << '1' << '\n';
}