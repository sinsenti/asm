#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

extern "C" void __cdecl perestancdecl(int* arr, int size);
extern "C" void __stdcall perestanstdcall(int* arr1, int size);
extern "C" void __fastcall perestanfastcall(int size, int* arr2);

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int sizee = 6;
 
    int* arr = new int[sizee];
    cout << "Исходный массив: ";
    for (int i = 0; i < sizee; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    perestancdecl(arr, sizee);
    cout << '\n';
    cout << "Массив после обмена: ";
    for (int i = 0; i < sizee; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << '\n';
    int* arr1 = new int[sizee];
    cout << "Исходный массив2: ";
    for (int i = 0; i < sizee; i++) {
        arr1[i] = rand() % 100;
        cout << arr1[i] << " ";
    }
    cout << endl;

    perestanstdcall(arr1, sizee);

    cout << "Массив 2 после обмена: ";
    for (int i = 0; i < sizee; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int* arr2 = new int[sizee];
    cout << "Исходный массив 3: ";
    for (int i = 0; i < sizee; i++) {
        arr2[i] = rand() % 100;
        cout << arr2[i] << " ";
    }
    cout << endl;

    perestanfastcall(sizee, arr2);

    cout << "Массив 3 после обмена: ";
    for (int i = 0; i < sizee; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
   
    delete[] arr;
    delete[] arr1;
    delete[] arr2;

    return 0;
}