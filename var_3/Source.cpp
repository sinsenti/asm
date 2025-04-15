#include <iostream>
#include <ctime>

extern "C" int __stdcall FindMinDigitSumIndex(unsigned int* arr, int size);

int main(){
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    const int SIZE = 10;
    unsigned int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 50;
    }
    for (int i = 0; i < SIZE; i++)
        std::cout << arr[i]<<" ";
    std::cout << '\n';
    int index = FindMinDigitSumIndex(arr, SIZE);
    std::cout << "Индекс элемента с минимальной суммой цифр: " << index << std::endl;

    return 0;
}
