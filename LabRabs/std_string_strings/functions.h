#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <windows.h>

bool IsLetterLatinas(char);
void ExtractWordsFromString(const std::string&, std::string*&, int32_t&);
std::string MergeSortedWords(std::string*, int32_t, std::string*, int32_t);

#endif