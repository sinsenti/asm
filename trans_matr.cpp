#include <iostream>
int main() {

  int A[3][4] = {{100, 2, 33, 4}, {5, 600, 77, 8}, {900, 10, 11, 1200}};
  int B[4][3];
  int n = 3, m = 4;
  _asm {
mov ecx,0 ; i  номер текущей строки A
begin_n:
mov ebx,0 ; j  номер текущего элемента A
begin_m:
    // адрес A[i][j] равен A+(i*m+j)*размер элемента
    // вычисляем i*m+j
mov eax,m
mul ecx
add eax,ebx
mov esi,eax ; esi  (i*m+j)
mov edi,A[esi*4] ; edi  A[i][j]
    // адрес B[j][i] равен B+(j*n+i)*размер элемента
    // вычисляем j*n+i
mov eax,n
mul ebx
add eax,ecx
mov esi,eax ; esi  (j*n+i)
mov B[esi*4],edi ; B[j][i]  edi
inc ebx ; к следующему элементу в строке
cmp ebx,m
jl begin_m ; не все элементы обработаны
inc ecx ; к следующей строке
cmp ecx,n
jl begin_n ; не все строки обработаны
  }
}
