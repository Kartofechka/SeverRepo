#include <iostream>
#include "functions.h"


size_t InputSize() {
    size_t size{};
        std::cout << "������� ������ �������: \n";
        std::cin >> size;
        if (std::cin.fail()) {
            throw std::invalid_argument("������: ������� �������� ��������, ��������� ����� ����� � �������� �� 1 �� 100");
        }
        if (size < 1 || size > MAX_SIZE) {
            throw std::out_of_range("������: ������ ������ ���� � �������� �� 1 �� 100");
        }
    return size;
}


int16_t SelectChoice() {
        std::cout << "�������� ���� �� ������������ ��������� ����:\n";
        int16_t choice{};
        std::cin >> choice;
        if (choice != 1 && choice != 2) {
             throw std::invalid_argument("������: �������� 1 ��� 2.");
        }
        return choice;
}

void FillArrayByRandom(double* array, size_t size, double min_value, double max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution <> dist(min_value, max_value);
    for (size_t i = 0; i < size; ++i) {
        array[i] = dist(rd);
    }
}

