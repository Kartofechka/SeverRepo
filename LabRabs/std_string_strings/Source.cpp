#include "functions.h"


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string first_string;
    std::string second_string;
    std::cout << "¬ведите первую строку: ";
    std::getline(std::cin, first_string);
    std::cout << "¬ведите вторую строку: ";
    std::getline(std::cin, second_string);
    std::string* words1 = nullptr;
    std::string* words2 = nullptr;
    int wordCount1 = 0, wordCount2 = 0;
    ExtractWordsFromString(first_string, words1, wordCount1);
    ExtractWordsFromString(second_string, words2, wordCount2);
    std::string mergedString = MergeSortedWords(words1, wordCount1, words2, wordCount2);
    std::cout << "–езультат: " << mergedString << std::endl;
    delete[] words1;
    delete[] words2;

    return 0;
}
