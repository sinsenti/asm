#include <iostream>

using namespace std;

int main() {
  // setlocale(LC_ALL, ".1251");

  int money;
  int price;
  int change = -1;

  cout << "Введите деньги (в копейках): ";
  cin >> money;

  cout << "Введите цену хлеба (в копейках): ";
  cin >> price;

  _asm {
        mov eax, money
        mov ecx, price
        xor esi, esi

        cmp eax, 0
        jle failexit

        cycle :
        cmp eax, ecx
            jge done

            test esi, 1
            jz papa

            mama :
        imul eax, 3
            jmp cont

            papa :
        add eax, eax

            cont :
        inc esi    
            push eax
            push ebx
            push edx
            push ecx

            mov ebx, esi
            mov edx, 0
            mov eax, ebx
            mov ecx, 5
            div ecx // edx = остаток от деления на 5

            cmp edx, 0
            jne end_ice // Не кратно 5, пропускаем

            pop ecx
            pop edx
            pop ebx
            pop eax

            cmp eax, ecx
            jge cycle   

            sub eax, 50 // Вычитаем мороженое

     // Округление до рубля
            add eax, 50
            mov ebx, 100
            xor edx, edx
            div ebx // eax = (eax + 50) / 100
            imul eax, ebx

         // Проверка на нечётность рублей
            mov ebx, eax
            xor edx, edx
            mov ecx, 100
            div ecx // eax = рубли
            test eax, 1
            jz even_rub

         // Увеличиваем на 1/3
            mov eax, ebx
            mov ecx, 3
            xor edx, edx
            div ecx // eax = сумма / 3
            add ebx, eax
            mov eax, ebx

            even_rub :
        push eax
            push ecx
            jmp cycle

            end_ice :
        pop ecx
            pop edx
            pop ebx
            pop eax
            jmp cycle

            done :
        sub eax, ecx
            mov change, eax

  }

  if (change >= 0) {
    cout << "Сдача: " << charge << " копеек.\n";
  }
  else {
    cout << "Не получилось купить хлеб\n";
  }

  return 0;
}
