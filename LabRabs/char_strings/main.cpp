//8 11 

//только char *, максимальная длина строки = 300.
//Словом в строке считается последовательность букв латиноского алфавита,
// остальные символы являются разделителями между словами. За один просмотр символов
// строки найти все слова с максимальной долей гласных букв и занестти их в новую строку.
// Слова в новой строке должны разделяться ровно одним пробелом.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>
#include "functions.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char string[300];
	char result[300];
	result[0] = '\0';
	std::cout << "Введите вашу строку:\n";
	std::cin.getline(string, 300);
	FindingWordsWithMaxVowelsRatio(string, result);
	std::cout << "Слова с максимальной долей гласных:\n" << result << std::endl;
	return 0;
}