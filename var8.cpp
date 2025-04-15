#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  srand(time(NULL));

  int n;
  cout << "Введите количество элементов массива: ";
  cin >> n;

  int *arr = new int[n];

  int K;
  cout << "Введите число K: ";
  cin >> K;

  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 21 - 10;
  }

  cout << "Исходный массив:\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

  _asm {
    
        mov ecx, n
        cmp ecx, 0
        je fill_zeros_done; если массив пустой, переход к заполнению нулями(на всякий случай)

    // esi указывает на начало массива
        mov esi, arr

        // edi – индекс для записи оставшихся элементов (j = 0)
        xor edi, edi
        // ebx – текущий индекс перебора (i = 0)
        xor ebx, ebx

        loop_process :
        cmp ebx, ecx
            jge fill_zeros; если обработали все элементы - переходим к заполнению нулями

                                  // Загружаем текущий элемент и сохраняем его
                                  // во временной области (на стек)
            mov eax, dword ptr[esi + ebx * 4]
            push eax; сохраняем оригинальное значение(оно понадобится, если элемент остаётся)

    // Вычисляем модуль текущего числа, работая с числом в eax
    // Для вычисления модуля используется метод: abs(x)= (x ^ sign) - sign, где
    // sign = x >> 31.
            mov edx, eax
            sar edx, 31; edx = 0 для неотрицательных, = -1 для отрицательных чисел
            xor eax, edx
            sub eax, edx; в eax теперь находится абсолютное значение

        // Сравниваем полученное значение с K
            mov edx, K
            cmp eax, edx
            jle skip_item; если модуль <= K, элемент не копируем

        // Если модуль > K, восстанавливаем исходное значение и копируем его в
        // позицию с индексом edi
            pop eax; возвращаем оригинальное число
            mov dword ptr[esi + edi * 4], eax
            inc edi
            jmp continue_loop

            skip_item :
        pop eax; удаляем сохранённое значение со стека(не копируем элемент)

            continue_loop:
        inc ebx
            jmp loop_process

            fill_zeros :
    // Заполняем оставшиеся элементы (от индекса edi до n-1) нулями.
        mov ebx, edi; ebx = текущий индекс заполнения
            loop_zeros :
        cmp ebx, n
            jge fill_zeros_done
            mov dword ptr[esi + ebx * 4], 0
            inc ebx
            jmp loop_zeros

            fill_zeros_done :
    // Выход из ассемблерной вставки
        nop
  }

  cout << "Преобразованный массив:\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

  delete[] arr;
  return 0;
}
