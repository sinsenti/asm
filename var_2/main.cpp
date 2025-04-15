#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

extern "C" int __stdcall FindMostFrequent1(const int* array, int size);
extern "C" int __cdecl FindMostFrequent2(const int* array, int size);
extern "C" int __fastcall FindMostFrequent3(const int* array, int size);

const int SIZE = 10;

bool isNumber(string input) {
    bool hasMinus = false;
    bool hasDigit = false;
    for (const char c : input) {
        if (!isdigit(c)) {
            if (c == '-' && !hasMinus && !hasDigit) {
                hasMinus = true;
            }
            else {
                return false;
            }
        }
        hasDigit = true;
    }
    return true;
}

int main() {
    system("chcp 1251");

    int array[SIZE];

    string input;
    int max = 0;
    cout << "Введите максимальное значение элемента массива: ";
    while (getline(cin, input)) {
        if (isNumber(input) && (max = stoi(input)) >= 0) {
            break;
        }
        cerr << "Введите неотрицательное число: ";
    }

    for (int i = 0; i < SIZE; ++i) {
        array[i] = rand() % (max + 1);
    }

    cout << "Массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    int result1 = FindMostFrequent1(array, SIZE);
    cout << "Самый часто встречаемый элемент (stdcall): " << result1 << endl;
    int result2 = FindMostFrequent2(array, SIZE);
    cout << "Самый часто встречаемый элемент (cdecl): " << result2 << endl;
    int result3 = FindMostFrequent3(array, SIZE);
    cout << "Самый часто встречаемый элемент (fastcall): " << result3 << endl;

    return 0;
}