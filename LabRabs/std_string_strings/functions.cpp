#include "functions.h"

bool IsLetterLatinas(char ch) {
    return std::isalpha(ch) && (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z');
}

void ExtractWordsFromString(const std::string& input, std::string*& words, int32_t& count_of_words) {
    std::string word;
    count_of_words = 0;
    int32_t max_count_of_words = input.size() / 2 + 1;
    words = new std::string[max_count_of_words];

    for (char ch : input) {
        if (IsLetterLatinas(ch)) {
            word += std::tolower(ch);
        }
        else if (!word.empty()) {
            words[count_of_words++] = word;
            word.clear();
        }
    }
    if (!word.empty()) {
        words[count_of_words++] = word;
    }
}

std::string MergeSortedWords(std::string* words_from_first_string, int32_t word_count_in_first_string, std::string* words_from_second_string, int32_t word_count_in_second_string) {
    int32_t count_all_words = word_count_in_first_string + word_count_in_second_string;
    std::string* merged = new std::string[count_all_words];
    std::copy(words_from_first_string, words_from_first_string + word_count_in_first_string, merged);
    std::copy(words_from_second_string, words_from_second_string + word_count_in_second_string, merged + word_count_in_first_string);
    std::sort(merged, merged + count_all_words);
    std::ostringstream result;
    for (int i = 0; i < count_all_words; ++i) {
        if (i > 0) {
            result << " ";
        }
        result << merged[i];
    }

    delete[] merged;
    return result.str();
}