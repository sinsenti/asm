#include <iostream>
using namespace std;

int main() {
  // setlocale(LC_ALL, ".1251");

  int start;
  int cost;
  int result;
  cout << "Введите изначальное количество денег: ";
  cin >> start;
  cout << "Введите стоимость хлеба: ";
  cin >> cost;
  int n = 0;
  _asm {
    mov eax, start
    mov ebx, cost
    mov ecx, n

  loop1:
    cmp eax, ebx
    jge end1
    test n, 1
    jz dad
    imul eax, 3
    inc n
    jmp loop1


  dad:
    imul eax, 2
    inc n
    jmp loop1


  end1:
    sub eax, ebx
    mov result, eax

  }
  cout << "сдача: " << result;
  return 0;
}
