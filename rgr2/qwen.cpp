#include <climits>
#include <iostream>

int main() {
  const int N = 5;
  int arr1[N] = {3, 1, 4, 5, 2};
  int arr2[N] = {5, 2, 3, 6, 7};
  int min_value = INT_MAX;

  for (int i = 0; i < N; i++) {
    int element = arr1[i];
    int found = 0;

    _asm {
            push esi
            push ecx
            mov eax, element // Текущий элемент из первого массива
            mov esi, arr2 // Указатель на начало второго массива
            mov ecx, N // Количество элементов во втором массиве
        check_loop:
            cmp [esi], eax // Сравниваем элементы
            je found_label // Если равны, элемент найден
            add esi, 4 // Переход к следующему элементу (int - 4 байта)
            loop check_loop // Повторяем цикл
            jmp not_found // Если не найден, переходим
        found_label:
            mov found, 1 // Устанавливаем флаг found в 1
        not_found:
            pop ecx
            pop esi
    }

    if (!found && element < min_value) {
      min_value = element;
    }
  }

  if (min_value != INT_MAX) {
    std::cout << "Minimum element not present in the second array: "
              << min_value << std::endl;
  } else {
    std::cout << "All elements are present in the second array." << std::endl;
  }

  return 0;
}
