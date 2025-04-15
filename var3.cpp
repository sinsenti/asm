#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(NULL));
  const int size = 10;
  int my_size = size;
  int array[size];
  int resultIndex;
  int minSum;

  // Заполнение массива случайными числами и вывод его на экран
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 1000; // числа от 0 до 999
    cout << array[i] << " ";
  }
  cout << "\n";

  _asm {
    lea esi, array
    mov ecx, 0 // index
    mov eax, [esi] // load first element
    mov edi, 0 // for sum of digit
    cmp eax, 0
    je first_sum_done

  first_digit_loop:
    xor edx, edx
    mov ebx, 10
    div ebx
    add edi, edx
    cmp eax, 0
    jne first_digit_loop

  first_sum_done:
    mov minSum, edi
    mov resultIndex, 0
    mov ecx, 1

  next_element:
    cmp ecx, my_size
    jge finished_loop
    mov eax, [esi + ecx * 4]
    mov edi, 0
    cmp eax, 0
    je current_sum_done

  current_digit_loop:
    xor edx, edx
    mov ebx, 10
    div ebx
    add edi, edx
    cmp eax, 0
    jne current_digit_loop

    current_sum_done:
    mov ebx, minSum
    cmp edi, ebx
    jge skip_update

    mov minSum, edi
    mov resultIndex, ecx

    skip_update:
    inc ecx
    jmp next_element

    finished_loop:

  }

  cout << "Индекс элемента с минимальной суммой цифр: " << resultIndex << endl;
  return 0;
}
