#include <iostream>
#include <vector>
using namespace std;

int main() {

  //  setlocale(LC_ALL, ".1251");

  vector<int> primes;
  int n = 0;

  for (int num = 100; num <= 999; num++) {
    bool isPrime = false;
    _asm {
      mov esi, 0
      mov ebx, 0
      mov eax, num
      test eax, 1;
      jz not_prime;
      mov ecx, 3;
      mov esi, eax;
  check_loop:
      mov eax, esi;
      mov ebx, ecx
      imul ebx, ecx;
      cmp ebx, esi;
      jg is_prime;
      xor edx, edx;
      div ecx;
      cmp edx, 0
      jz not_prime;
      add ecx, 2;
      jmp check_loop;
  is_prime:
      mov isPrime, 1;
      inc n
            
        not_prime:
    }
    if (isPrime) {
      primes.push_back(num);
    }
  }

  cout << "Трехзначные простые числа:\n";
  for (size_t i = 0; i < primes.size(); ++i) {
    cout << primes[i] << " ";
  }
  cout << endl;
  cout << n << endl;

  return 0;
}
