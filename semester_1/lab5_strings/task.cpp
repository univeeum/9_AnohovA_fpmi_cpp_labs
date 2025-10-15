#include <climits>
#include <iostream>
#include <vector>

void find_words(const std::string &sep_line, const std::string &line, std::vector<std::string> &words) {
    
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
}

void get_longest(const std::vector<std::string> &words) {

    if (words.empty()) {
        std::cout << "There are no words in string\n";
        return;
    }
    
    size_t max_len = 0;
    for (const auto &word : words) {
        size_t now_len = word.length();
        max_len = std::max(max_len, now_len);
    }

    for (const auto &word : words) {
        size_t now_len = word.length();
        if (now_len == max_len)
            std::cout << word << ' ';
    }
    std::cout << '\n';
}

int main() {
    // Input separator string
    std::cout << "Input separator characters one after another\n";
    std::string sep_line;
    getline(std::cin, sep_line);

    // if no separators then use space symbol
    if (sep_line.empty()) {
        sep_line = " ";
    }

    // Input line 
    std::cout << "Input line\n";
    std::string line;
    getline(std::cin, line);

    // Find words in line
    std::vector<std::string> words;
    find_words(sep_line, line, words);

    // Print longest words
    get_longest(words);

    return 0;
}