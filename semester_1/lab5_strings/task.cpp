#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool IsTextChar(const char c) {
    return std::isalnum(static_cast<unsigned char>(c));
}

void GetWords(const std::string &text, std::vector<std::string> &words) {
    if (text.empty()) {
        return;
    }

    std::string word;
    for (const char sym : text) {
        if (IsTextChar(sym)) {
            word += sym;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
}

void GetLongestWords(std::string &result, const std::vector<std::string> &words) {
    if (words.empty()) {
        return;
    }

    size_t max_len = 0;
    for (const std::string &word : words) {
        max_len = std::max(max_len, word.length());
    }

    for (const std::string &word : words) {
        if (word.length() == max_len) {
            result += word;
            result += " ";
        }
    }
}

bool GetLine(std::string &line) {
    std::cout << "Input line:\n";
    return static_cast<bool>(std::getline(std::cin, line));
}

void PrintString(const std::string &result) {
    if (result.empty()) {
        std::cout << "Nothing to display :(\n";
    } else {
        std::cout << "Result string:\n" << result << '\n';
    }
}

int main() {
    try {
        std::string text;
        if (!GetLine(text)) {
            throw "Input error\n";
        }
        std::vector<std::string> words;
        GetWords(text, words);

        std::string result;
        GetLongestWords(result, words);
        PrintString(result);

    } catch (const char *msg) {
        std::cerr << msg << '\n';
    }
    return 0;
}