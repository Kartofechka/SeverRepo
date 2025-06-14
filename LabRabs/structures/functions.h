#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

//Работа с файлом и информацией
bool IsValidDouble(double&, const std::string);
void InPutArrayFromFile(std::ifstream&, double*&, int32_t);
void InPutSizeOfArrayFromConsole(int32_t&);
void InPutArrayFromConsole(double*&, int32_t);
void ChooseHowToFillArray(int32_t &);
void FindSizeOfArray(std::ifstream&, int32_t&, int32_t);
void FillArray(std::ifstream&, double*&, int32_t, int32_t);
void ChooseSort(int32_t&);
void OutPutArrayInConsole(double*&, int32_t);
void OutPutArrayInFile(std::ofstream&, double*&, int32_t);
void SortArray(double*, int32_t, int32_t&);
void ChooseOutPut(int32_t&);
void OutPutArray(int32_t&, std::ofstream &, double*, int32_t);


//Сортировки
void BubbleSort(double*, int32_t );
void SelectionSort(double*, int32_t);
void QuickSort(double*, int32_t, int32_t);
int32_t Partitions(double*, int32_t, int32_t);
void InsertionSort(double*, int32_t);
void Merge(double*, int32_t, int32_t, int32_t);
void MergeSort(double*, int32_t left, int32_t);
int32_t CountDigitAfterDot(double);
int32_t CompareByFractionDigits(const void*, const void*);
void Qsort(double*, int32_t);
void FromBiggerToLower(double*, int32_t);


template<typename T>
void FromBiggerToLower(T* array, int32_t size_of_array) {
	int32_t i = {};
	while (i != size_of_array || i < size_of_array) {
		std::swap(array[i], array[size_of_array - 1]);
		++i;
		--size_of_array;
	}
}

template<typename T>
int32_t Partitions(T* array, int32_t start_index, int32_t end_index) {
	T pivot = array[end_index];
	int32_t i = start_index - 1;
	for (int32_t j = start_index; j < end_index; ++j) {
		if (array[j] < pivot) {
			++i;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[end_index]);
	return i + 1;
}

template<typename T>
void QuickSort(T* array, int32_t start_index, int32_t endI_index) {
	if (start_index < endI_index) {
		int32_t pivotIndex = Partitions(array, start_index, endI_index);
		QuickSort(array, start_index, pivotIndex - 1);
		QuickSort(array, pivotIndex + 1, endI_index);
	}
}


struct Student {
	std::string name;
	std::string surname;
	std::string group;
	std::string clas;
	int32_t marks[5]{};

	double CountEverageMark() const {
		double everage_mark = {};
		for (int32_t i = {};i < 5;++i) {
			everage_mark += marks[i];
		}
		return everage_mark;
	}

	bool operator<(const Student& other) const {
		return CountEverageMark() < other.CountEverageMark();
	}

	bool operator>(const Student& other) const {
		return CountEverageMark() > other.CountEverageMark();
	}

	bool operator==(const Student& other) const {
		return CountEverageMark() == other.CountEverageMark();
	}

	bool operator<=(const Student& other) const {
		return CountEverageMark() <= other.CountEverageMark();
	}

	bool operator>=(const Student& other) const {
		return CountEverageMark() >= other.CountEverageMark();
	}

};

void InputNumberOfStudents(int32_t&);
void InputInfoAboutStudents(Student*, int32_t);
double CountAverageMark(Student&);
void OutPutStudent(Student*, int32_t);
void InputNumberOfStudents(int32_t&);
void SortStudentsByEverageMark(Student*, int32_t);

#endif