#include <ctime>
#include <iostream>

using namespace std;

int main() {
  srand(time(NULL));
  const int size = 10;
  int my_size = size;
  int result;
  int array[size];
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 5 + 1;
    cout << array[i] << ' ';
  }
  cout << '\n';

  _asm {
    lea esi, array
    mov ecx, [my_size]
    dec ecx

outer_loop:
    mov ebx, 0
    mov edi, ecx

inner_loop:
    mov eax, [esi + ebx * 4]
    mov edx, [esi + ebx * 4 + 4]
    cmp eax, edx
    jbe no_swap

    mov [esi + ebx * 4], edx
    mov [esi + ebx * 4 + 4], eax


no_swap:
    inc ebx
    cmp ebx, edi
    jl inner_loop
    dec ecx
    jnz outer_loop

  }

  for (int i = 0; i < size; i++) {
    cout << array[i] << ' ';
  }
  return 0;
}
