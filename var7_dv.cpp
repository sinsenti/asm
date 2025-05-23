#include <iostream>
using namespace std;

int main() {
  // Ввод исходного числа n (натуральное число, 32-битное)
  unsigned int n;
  // Ввод m – количество младших цифр, сумму которых нужно вычислить (8-битное
  // число)
  unsigned char m;

  cout << "Введите число n (натуральное, длиной в двойное слово): ";
  cin >> n;
  cout << "Введите число m (натуральное, длиной в байт): ";
  cin >> m;

  int sum = 0; // Итоговая сумма m младших цифр

  _asm {
        mov eax, n // EAX = n
        mov cl, m // CL = m (счётчик цифр)
        xor ebx, ebx // EBX будем использовать для накопления суммы; обнуляем EBX

        digit_loop :
        cmp cl, 0 // Если m цифр уже обработаны, выходим из цикла
            je finish_loop
            xor edx, edx // Обнуляем EDX – требуется для корректного деления
            mov ecx, 10 // ECX = 10 (делитель для получения последней цифры)
            div ecx // Делим EAX на 10:
           //   - после деления: EAX содержит частное (число без последней
           //   цифры),
           //   - EDX содержит остаток (текущую младшую цифру)
            add ebx, edx // Добавляем остаток к сумме (EBX = EBX + цифра)
            dec cl // Уменьшаем счётчик обработанных цифр
            jmp digit_loop // Переходим к следующей итерации

            finish_loop :
        mov sum, ebx // Сохраняем итоговую сумму в переменную sum
  }

  cout << "Сумма " << static_cast<int>(m) << " младших цифр числа " << n
       << " равна: " << sum << endl;
  return 0;
}
