#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int N =3; // ������ ���������� �������

// ��������� ������� � ��������� �������
extern "C" int __cdecl productDiagonalCdecl(int* matrix, int size);
extern "C" int __stdcall productDiagonalStdcall(int* matrix, int size);
extern "C" int __fastcall productDiagonalFastcall(int size, int* matrix);

void printMatrix(int* matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i * size + j] << "\t";
        }
        cout << endl;
    }
}

void fillMatrix(int* matrix, int size) {
    for (int i = 0; i < size * size; ++i) {
        matrix[i] = rand() % 10 + 1;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(nullptr));

    int matrix[N][N];
    fillMatrix((int*)matrix, N);

    cout << "�������� ������� " << N << "x" << N << ":" << endl;
    printMatrix((int*)matrix, N);

    // ��������� ������������ ������� ���������
    cout << "\n1. ��������� cdecl: ";
    int product = productDiagonalCdecl((int*)matrix, N);
    cout << "������������ ���������: " << product << endl;

    cout << "2. ��������� stdcall: ";
    product = productDiagonalStdcall((int*)matrix, N);
    cout << "������������ ���������: " << product << endl;

    cout << "3. ��������� fastcall: ";
    product = productDiagonalFastcall(N, (int*)matrix);
    cout << "������������ ���������: " << product << endl;

    return 0;
}
