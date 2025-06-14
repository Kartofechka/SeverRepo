#include "functions.h"


int main() {
    try {
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        std::ifstream ifile("text.txt");
        std::ofstream ofile("output_text.txt");
        int32_t size_of_array = {};
        int32_t numOfVariant = {};
        int32_t outputNumOfVariant = {};
        ChooseHowToFillArray(numOfVariant);
        FindSizeOfArray(ifile, size_of_array, numOfVariant);
        double* nums = new double[size_of_array];
        FillArray(ifile, nums, size_of_array, numOfVariant);
        ChooseSort(numOfVariant);
        SortArray(nums, size_of_array, numOfVariant);
        OutPutArray(numOfVariant, ofile, nums, size_of_array);
        ifile.close();
        ofile.close();
        delete[] nums;
        InPutSizeOfArrayFromConsole(size_of_array);
        Student* students = new Student[size_of_array];
        InputInfoAboutStudents(students, size_of_array);
        QuickSort(students, 0, size_of_array - 1);
        ChooseSort(numOfVariant);
        OutPutStudent(students, size_of_array);

        delete[] students;
        return 0;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
