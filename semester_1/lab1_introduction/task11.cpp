#include <iostream> 
#include <algorithm>


std::string DecToBin(int n) {
    std::string ans = "";
    int rem;

    while (n > 0) {
        rem = n % 2;
        n /= 2;
        ans += (rem + '0');
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::string DecToHaxadec(int n) {
    std::string ans = "";
    int rem;

    while (n > 0) {
        rem = n % 16;
        n /= 16;

        if (rem < 10) {
            ans += (rem + '0');
        }
        else {
            if (rem == 10) ans += "A";
            if (rem == 11) ans += "B";
            if (rem == 12) ans += "C";
            if (rem == 13) ans += "D";
            if (rem == 14) ans += "E";
            if (rem == 15) ans += "F";
        }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    //std::cout << DecToBin(13) << " " << DecToHaxadec(13) << '\n'; 

    std::cout << DecToBin(n) << ' ' << DecToHaxadec(n) << '\n';
}