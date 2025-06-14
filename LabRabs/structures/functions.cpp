#include "functions.h"


void InPutSizeOfArrayFromConsole(int32_t& size_of_array) {
	std::cout << "Введите размер массива:\n";
	std::cin >> size_of_array;
	if (size_of_array <= 0) {
		throw std::invalid_argument("Размер массива должен быть положительным");
	}
}


void FindSizeOfArrayFromFile(std::ifstream& file, int32_t& size_of_array) {
	std::size_t pos = {};
	std::string token;
	double num = {};
	int32_t counter = {};
	while (file >> token) {
		num = std::stod(token,&pos);
		if (pos == token.length()) {
			++counter;
		}
	}
	size_of_array = counter;
	if (size_of_array == 0) {
		throw std::invalid_argument("В файле должен содержаться положительное число");
	}
	file.clear();
	file.seekg(0, std::ios::beg);
}


bool IsValidDouble(double& number, const std::string token) {
	std::size_t pos = {};
    number = std::stod(token, &pos);
	return pos == token.length();  
}


void InPutArrayFromFile(std::ifstream& file, double*& array, int32_t size_of_array) {
	std::string token;
	double num = {};
	int32_t i = {};
	while (file >> token && i < size_of_array) {
		if (IsValidDouble(num,token) == true) {
		  array[i] = num;
		  ++i;
		}	
	}
}


void InPutArrayFromConsole(double*& array, int32_t size_of_array) {
	std::cout << "Введите элементы массива\n";
	for (int32_t i = {};i < size_of_array;++i) {
		std::cin >> array[i];
	}
}


void OutPutArrayInConsole(double*& array, int32_t size_of_array) {
	std::cout << "Отсортированный массив:\n";
	for (int32_t i = {};i < size_of_array;++i) {
		std::cout << array[i] << '\n';
	}
}


void OutPutArrayInFile(std::ofstream& ofile, double*& array, int32_t size_of_array) {
	for (int32_t i = {}; i < size_of_array; ++i) {
		ofile << array[i];
		if (i < size_of_array - 1) {
			ofile << " ";
		}
	}
	std::cout << "Массив записан в \"out_text.txt\"\n";
}


void ChooseHowToFillArray(int32_t & num_of_variant) {
	std::cout << "Выбор способа заполнения массива:\n";
	std::cout << "[1] Из консоли\n";
	std::cout << "[2] Из файла\n";
	std::cin >> num_of_variant;
	if (num_of_variant != 1 && num_of_variant != 2) {
		throw std::invalid_argument("Неверный выбор");
	}
}


void FindSizeOfArray(std::ifstream& file, int32_t& size_of_array, int32_t num_of_variant) {
	if (num_of_variant == 1) {
		InPutSizeOfArrayFromConsole(size_of_array);
	}
	else {
		FindSizeOfArrayFromFile(file, size_of_array);
	}
}


void FillArray(std::ifstream& file,double*& array, int32_t size_of_array, int32_t num_of_variant) {
	if (num_of_variant == 1) {
		InPutArrayFromConsole(array, size_of_array);
	}
	else {
		InPutArrayFromFile(file, array, size_of_array);
	}
}


void ChooseSort(int32_t& num_of_variant) {
	std::cout << "Выбор способа сортировки:\n";
	std::cout << "[1]: Пузырек\n";
	std::cout << "[2]: Сортировка выбором\n";
	std::cout << "[3]: Сортировка вставками\n";
	std::cout << "[4]: Быстрая сортировка\n";
	std::cout << "[5]: Слиянием\n";
	std::cout << "[6]: Быстрая сортировка по значениям после запятой\n";
	std::cin >> num_of_variant;
	if (num_of_variant < 1 && num_of_variant > 6) {
		throw std::invalid_argument("Неверный выбор");
	}
}


void ChooseTypeOfSort(int32_t& num_of_variant) {
	std::cout << "Выбор параметров сортировки:\n";
	std::cout << "[1]: От меньшего к большему\n";
	std::cout << "[2]: От большего к меньшему\n";
	std::cin >> num_of_variant;
	if (num_of_variant != 1 && num_of_variant != 2) {
		throw std::invalid_argument("Неверный выбор");
	}
}


void SortArray(double * array, int32_t size_of_array, int32_t & num_of_variant) {
	void (*simpleSorts[3])(double*, int32_t) = { BubbleSort, SelectionSort,InsertionSort };
	void (*compositeFunctions[2])(double*, int32_t, int32_t) = { QuickSort,MergeSort };

	if (num_of_variant <= 3) {
		simpleSorts[num_of_variant - 1](array, size_of_array);
	}
	else if(num_of_variant <= 5) {
		compositeFunctions[num_of_variant - 4](array, 0, size_of_array - 1);
	}
	else {
		qsort;
	}

	ChooseTypeOfSort(num_of_variant);
	if (num_of_variant == 2) {
		FromBiggerToLower(array, size_of_array);
	}
}


void ChooseOutPut(int32_t & num_of_variant) {
	std::cout << "Выбор места куда выводить результат\n";
	std::cout << "[1]: В файл\n";
	std::cout << "[2]: В консоль\n";
	std::cin >> num_of_variant;
	if (num_of_variant != 1 && num_of_variant != 2) {
		throw std::invalid_argument("Неверный выбор");
	}
}


void OutPutArray(int32_t & num_of_variant, std::ofstream& out_file, double* array, int32_t size_of_array){
	if (num_of_variant == 1) {
		OutPutArrayInFile(out_file,array, size_of_array);
	}
	else {
		ChooseOutPut(num_of_variant);
		if (num_of_variant == 1) {
			OutPutArrayInFile(out_file, array, size_of_array);
		}
		else {
			OutPutArrayInConsole(array, size_of_array);
		}
	}
}


void BubbleSort(double* array, int32_t size_of_array) {
	bool isSwapped = true;
	while (isSwapped == true) {
		isSwapped = false;
		for (int32_t i = {};i < size_of_array - 1;++i) {
			if (array[i] > array[i + 1]) {
				std::swap(array[i], array[i + 1]);
				isSwapped = true;
			}
		}
		size_of_array -= 1;
	}
}


void SelectionSort(double* array, int32_t size_of_array) {
	for (int32_t i = {};i < size_of_array - 1;++i) {
		int32_t index_of_min = { i };
		for (int32_t j = { i + 1 };j < size_of_array;++j) {
			if (array[j] < array[index_of_min]) {
				index_of_min = j;
			}
		}
		if (index_of_min != i) {
			std::swap(array[i], array[index_of_min]);
		}
	}
}


int32_t Partitions(double* array, int32_t start_index, int32_t end_index) {
	double pivot = { array[end_index]};
	int32_t i = {start_index - 1};
	for (int32_t j = { start_index };j < end_index;++j) {
		if (array[j] <= pivot) {
			++i;
			std::swap(array[j], array[i]);
		}
	}
	std::swap(array[i + 1], array[end_index]);
	return i + 1;
}


void QuickSort(double* array, int32_t start_index, int32_t end_index) {
	if (start_index < end_index) {
		int32_t index_of_pivot_element = { Partitions(array, start_index, end_index) };
		QuickSort(array, start_index, index_of_pivot_element - 1);
		QuickSort(array, index_of_pivot_element + 1, end_index);
	}
}


void InsertionSort(double* array, int32_t size_of_array) {
	for (int32_t i = { 1 };i < size_of_array;++i) {
		double key = array[i];
		int32_t j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}


void MergeSort(double* array, int32_t left, int32_t right) {
	if (left < right) {
		int32_t mid = (left + right) / 2;

		MergeSort(array, left, mid);

		MergeSort(array, mid + 1, right);

		Merge(array, left, mid, right);
	}
}


void Merge(double* array, int32_t left, int32_t mid, int32_t right) {
	int32_t size1 = mid - left + 1;     
	int32_t size2 = right - mid;        

	double* L = new double[size1];
	double* R = new double[size2];

	for (int32_t i = {}; i < size1; ++i)
		L[i] = array[left + i];           

	for (int32_t j = {}; j < size2; ++j)
		R[j] = array[mid + 1 + j];        

	int32_t i = {};
	int32_t j = {};
	int32_t k = { left };

	
	while (i < size1 && j < size2) {
		if (L[i] <= R[j]) {
			array[k] = L[i]; 
			++i;
		}
		else {
			array[k] = R[j];
			++j;
		}
		++k; 
	}

	while (i < size1) {
		array[k] = L[i];
		++i;
		++k;
	}

	while (j < size2) {
		array[k] = R[j];
		++j;
		++k;
	}

	delete[] L;
	delete[] R;
}


int32_t CountDigitAfterDot(double num) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(7) << num;
	std::string str = oss.str();
	int32_t pos = static_cast<int32_t>(str.find('.'));
	if (pos == std::string::npos) {
		return 0;
	}
	int32_t count = str.size() - pos - 1;
	while (count > 0 && str.back() == '0') {
		str.pop_back();
		--count;
	}
	return count;
}


int32_t CompareByFractionDigits(const void* a, const void* b) {
	double da = *(const double*)a;
	double db = *(const double*)b;

	int32_t countA = CountDigitAfterDot(da);
	int32_t countB = CountDigitAfterDot(db);

	return countA - countB;
}

void Qsort(double* array, int32_t size_of_array) {}


void FromBiggerToLower(double* array, int32_t size_of_array) {
	for (int32_t i = 0; i < size_of_array / 2; ++i) {
		std::swap(array[i], array[size_of_array - 1 - i]);
	}
}



void InputNumberOfStudents(int32_t& numbe_of_students) {
	std::cout << "Введите кол-во студентов:\n";
	std::cin >> numbe_of_students;
}


void InputInfoAboutStudents(Student * students, int32_t size_of_array) {
	for (int32_t i = {}; i < size_of_array; ++i) {
		std::cout << "Введите имя студента:\n";
		std::cin.ignore();
		getline(std::cin, students[i].name);
		std::cout << "Введите фамилию студента:\n";
		std::cin.ignore();
		getline(std::cin, students[i].surname);
		std::cout << "Введите курс студента:\n";
		std::cin.ignore();
		getline(std::cin, students[i].clas);
		std::cout << "Введите группу студента:\n";
		std::cin.ignore();
		getline(std::cin, students[i].group);
		std::cout << "Введите 5 отметок студента:\n";
		for (int32_t j = {}; j < 5; ++j) {
			std::cout << "Отметка " << j + 1 << " - " << '\n';
			std::cin >> students[i].marks[j];
		}
	}
}


double CountAverageMark(Student& student) {
	double averageMark = {};
	for (int32_t i = {}; i < 5; ++i) {
		averageMark += student.marks[i];
	}
	return averageMark / 5;
}


void SortStudentsByEverageMark(Student* students, int32_t number_of_students) {
	double* array_of_everage_marks = new double[number_of_students];
	int32_t everage_mark = {};
	for (int32_t i = {};i < number_of_students;++i) {
		for (int32_t j = {};j < 5; ++j) {
			everage_mark += students[i].marks[j];
		}
		everage_mark /= 5;
		array_of_everage_marks[i] = everage_mark;
	}
}

void OutPutStudent(Student* students, int32_t size_of_array) {

	std::cout << "Сортировка студентов по средней оценке\n";
	for (int32_t i = {}; i < size_of_array; ++i) {
		std::cout << "Имя: " << students[i].name << "\n";
		std::cout << "Фамилия: " << students[i].surname << "\n";
		std::cout << "Группа: " << students[i].group << "\n";
		std::cout << "Курс: " << students[i].clas << "\n";
		std::cout << "Оценки: ";
		for (int32_t j = {}; j < 5; ++j) {
			std::cout << students[i].marks[j] << " ";
		}
		std::cout << "\nСредняя оценка: " << CountAverageMark(students[i]) << "\n\n";
	}
}