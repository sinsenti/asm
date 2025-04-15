#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    unsigned int number;
    bool isSymmetric = false;

    
    cout << "Введите натуральное число: ";
    cin >> number;

    
    __asm {
        mov eax, [number]   
        mov ebx, 10         
        xor ecx, ecx        

        reverse_loop :
        xor edx, edx        
            div ebx            
            imul ecx, ebx     
            add ecx, edx       
            test eax, eax     
            jnz reverse_loop  

           
            mov eax, [number]
            cmp eax, ecx
            inc isSymmetric
    }


    if (isSymmetric) {
        cout << "Число " << number << " является симметричным." << endl;
    }
    else {
        cout << "Число " << number << " не является симметричным." << endl;
    }

    return 0;
}