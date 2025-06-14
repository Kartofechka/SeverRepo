#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "functions.h"
#include <cstring>
#include <windows.h>

bool IsLetterWovel(char letter) {
	letter = tolower(letter);
	return letter == 'a' || letter == 'e' || letter == 'y' || letter == 'u' || letter == 'i' || letter == 'o';
}


void CreateArrayOfDelimiters(const char* str, char* delimiters) {
	size_t count = 0;
	while (*str) {
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))) {
			delimiters[count++] = *str;
		}
		++str;
	}
	delimiters[count] = '\0';
}


int32_t CountVowelsInWord(const char* word) {
	int count = 0;
	while (*word) {
		if (IsLetterWovel(*word)) {
			count++;
		}
		word++;
	}
	return count;
}


double GetVowelRatio(const char* word) {
	int length = std::strlen(word);
	if (length == 0) return 0;
	return static_cast<double>(CountVowelsInWord(word)) / length;
}


void FindingWordsWithMaxVowelsRatio(const char* str, char* result) {
	char delims[256];
	CreateArrayOfDelimiters(str, delims);
	char temp_string[300];
	std::strcpy(temp_string, str);
	char* word = strtok(temp_string, delims);
	double max_ratio = 0;
	while (word != NULL) {
		double vowel_ratio = GetVowelRatio(word);
		if (vowel_ratio > max_ratio) {
			std::strcpy(result, word);
			max_ratio = vowel_ratio;
		}
		else if (vowel_ratio == max_ratio) {
			std::strcat(result, " ");
			std::strcat(result, word);
		}
		word = strtok(NULL, delims);
	}
}