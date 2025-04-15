#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int N = 10; // Размер массивов

int main() {
  srand(time(0)); // Инициализация генератора случайных чисел

  int arr1[N], arr2[N];   // Два массива по N элементов
  int minValue = INT_MAX; // Переменная для хранения минимального значения

  // Заполняем массивы случайными числами
  cout << "Array 1: ";
  for (int i = 0; i < N; ++i) {
    arr1[i] = rand() % 50 + 1; // Числа от 1 до 50
    cout << arr1[i] << " ";
  }
  cout << "\nArray 2: ";
  for (int i = 0; i < N; ++i) {
    arr2[i] = rand() % 50 + 1; // Числа от 1 до 50
    cout << arr2[i] << " ";
  }
  cout << endl;

  // Поиск минимального элемента, отсутствующего во втором массиве
  __asm {
        lea esi, arr1 // Загружаем адрес первого массива в ESI
        lea edi, arr2 // Загружаем адрес второго массива в EDI
        mov ecx, N // Счетчик элементов первого массива
        mov eax, INT_MAX // minValue = INT_MAX (максимальное значение int)
        
    loop_array1:
        mov edx, [esi] // Загружаем arr1[i] в EDX
        push ecx // Сохраняем счетчик
        mov ecx, N // Восстанавливаем счетчик для второго массива
        mov ebx, edi // Копируем адрес второго массива в EBX

    loop_array2:
        cmp [ebx], edx // Сравниваем arr2[j] и arr1[i]
        je found_match // Если нашли, пропускаем этот элемент
        add ebx, 4 // Переход к следующему элементу arr2
        loop loop_array2 // Проверяем следующий элемент второго массива

         // Если не нашли совпадение, проверяем минимум
        cmp edx, eax // Если arr1[i] < minValue
        jge continue_loop // Если нет, пропускаем
        mov eax, edx // Обновляем minValue

    continue_loop:
        pop ecx // Восстанавливаем счетчик
        add esi, 4 // Переход к следующему элементу arr1
        loop loop_array1 // Повторяем для всех элементов arr1
        jmp end_search

    found_match:
        pop ecx // Восстанавливаем счетчик
        add esi, 4 // Переход к следующему элементу arr1
        loop loop_array1 // Проверяем дальше

    end_search:
        mov minValue, eax // Записываем результат в C++ переменную
  }

  // Вывод результата
  if (minValue == INT_MAX) {
    cout << "No unique element found in the first array.\n";
  }
  else {
    cout << "Smallest unique number in Array 1 (not in Array 2): " << minValue
         << endl;
  }

  return 0;
}
