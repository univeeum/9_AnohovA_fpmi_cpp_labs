// 3. Строка состоит из слов, разделенных знаками препинания. Найти все
// самые длинные слова и занести их в новую строку. Слова в новой строке
// должны разделяться ровно одним пробелом.

#include <algorithm>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>

bool IsDelimiter(const char c) {
    const std::string delimiters = ",.!?;:-«»()";
    return delimiters.find(c) != std::string::npos;
}

std::vector<std::string> GetWords(const std::string &text) {
    // Get all words in text
    std::string::const_iterator start = text.begin();
    std::string::const_iterator word_end = text.begin();
    std::string::const_iterator end = text.end();

    std::vector<std::string> words;

    while (start != end) {
        start = std::find_if_not(start, end, IsDelimiter);
        if (start == end) {
            break;
        }
        word_end = std::find_if(start, end, IsDelimiter);

        // make word in words [start, word_end)
        words.emplace_back(start, word_end);
        start = word_end;
    }

    return words;
}

std::string GetLongestWords(const std::vector<std::string> &words) {
    // Choose longest words
    if (words.empty()) {
        return "";
    }

    size_t max_len = 0;
    for (const std::string &word : words) {
        max_len = std::max(max_len, word.length());
    }

    std::string result;
    for (const std::string &word : words) {
        if (word.length() == max_len) {
            if (!result.empty()) {
                result += " ";
            }
            result += word;
        }
    }
    return result;
}

std::string GetLine() {
    // Read text
    std::string line;
    std::cout << "Input line:\n";
    if (!std::getline(std::cin, line)) {
        throw std::runtime_error("Input error");
    }
    if (line.empty()) {
        throw std::invalid_argument("Empty input line\n");
    }
    return line;
}

void PrintString(const std::string &result) {
    // Print longest words
    if (result.empty()) {
        std::cout << "Nothing to display :(\n";
    } else {
        std::cout << "Result string:\n" << result << '\n';
    }
}

int main() {
    try {
        std::string text = GetLine();
        std::vector<std::string> words = GetWords(text);
        std::string result = GetLongestWords(words);
        PrintString(result);
    } catch (const std::exception &e) {
        std::cerr << e.what();
        return 1;
    }

    return 0;
}