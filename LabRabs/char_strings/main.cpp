//8 11 

//������ char *, ������������ ����� ������ = 300.
//������ � ������ ��������� ������������������ ���� ����������� ��������,
// ��������� ������� �������� ������������� ����� �������. �� ���� �������� ��������
// ������ ����� ��� ����� � ������������ ����� ������� ���� � �������� �� � ����� ������.
// ����� � ����� ������ ������ ����������� ����� ����� ��������.

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
	std::cout << "������� ���� ������:\n";
	std::cin.getline(string, 300);
	FindingWordsWithMaxVowelsRatio(string, result);
	std::cout << "����� � ������������ ����� �������:\n" << result << std::endl;
	return 0;
}