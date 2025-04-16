#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, ".1251");
  int y;
  _asm {
    mov edi, 5 // k=5
    xor eax, eax // sum=0

outer_loop: 
    mov esi, edi // n=k
inner_loop: 
    mov edx, esi // n
    imul edx, edx // n*n
    add edx, edi // n*n+k
    imul edx, edx //(n*n+k)^2
    add eax, edx // sum+=(n*n+k)^2

    inc esi // n++
    cmp esi, 5 // условия выхода из внутреннего цикла
    jle inner_loop 

    dec edi // k--
    cmp edi, 0 //  условие выхода из внешнего цикла
    jg outer_loop 

    mov y, eax
  }
  cout << "y= " << y << '\n';
  _asm {
    mov edi, 5
    xor eax, eax // sum =0
out_loop:
    mov esi, edi // n=k
in_loop:
    mov edx, esi // n
    imul edx, edx // n*n
    push edi // добавляем в стэк
    imul edi, edi // k*k
    add edx, edi // n*n+k*k
    pop edi // edi остается неизменным после умножения
    imul edx, edx //(n*n+k*k)^2
    add eax, edx // sum+=(n*n+k*k)^2

    inc esi // n+=
    cmp esi, 5 // условия выхода из внутреннего цикла
    jle in_loop

    dec edi // k--
    cmp edi, 0 // условия выхода из внешнего цикла
    jg out_loop 

    mov y, eax
  }
  cout << "y= " << y << '\n';

  return 0;
}
