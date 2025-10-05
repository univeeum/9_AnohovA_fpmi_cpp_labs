#include <climits>
#include <iostream>
#include <vector>

void get_longest(const std::vector<std::string> &words) {

    if (words.empty()) {
        std::cout << "There are no words in string\n";
        return;
    }
    // TODO size_t поч c ним что то не работает исправить
    int max_len = INT_MIN;
    for (const auto &word : words) {
        int now_len = static_cast<int>(word.length());
        max_len = std::max(max_len, now_len);
    }

    for (const auto &word : words) {
        int now_len = static_cast<int>(word.length());
        if (now_len == max_len)
            std::cout << word << ' ';
    }
    std::cout << '\n';
}

int main() {
    // TODO как нормально получить символы разделители? \n и тд и что если пользователь их не введет
    // Я не понимаю условие, дается строка или последовательность символов и что ваще АААА
    std::cout << "Input separator characters one after another\n";
    std::string sep_line;
    getline(std::cin, sep_line);

    // Если пользователь не ввел разделители, используем пробел по умолчанию
    if (sep_line.empty()) {
        sep_line = " ";
    }

    std::cout << "Input line\n";
    std::string line;
    getline(std::cin, line);

    std::vector<std::string> words;

    std::string word = "";
    for (char sym : line) {
        bool is_separator = false;
        for (char sep : sep_line) {
            if (sep == sym) {
                is_separator = true;
                break;
            }
        }

        if (is_separator) {
            if (!word.empty())
                words.push_back(word);
            word = "";
        } else {
            word += sym;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    get_longest(words);

    return 0;
}