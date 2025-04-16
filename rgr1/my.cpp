#include <iostream>

using namespace std;

int main() {
  int n = 0;
  cout << "start\n";

  _asm {
    mov eax, 1000
    mov esi, 1000
  first_loop:
    mov eax, esi
    dec eax
    dec esi
    cmp eax, 100
    je end_loop

    xor ebx, ebx
    test eax, 1
    jz first_loop
    mov ecx, 3
    mov esi, eax
  check_loop:
    mov eax, esi
    mov ebx, ecx
    imul ebx, ecx
    cmp ebx, esi
    jg is_prime
    xor edx, edx
    div ecx
    cmp edx, 0
    jz first_loop
    add ecx, 2
    jmp check_loop
  is_prime:
    inc n
    jmp first_loop


  end_loop:
  }
  cout << "end:\n";
  cout << n;
}
