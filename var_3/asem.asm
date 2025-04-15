; MinDigitSumIndex.asm
.386
PUBLIC _FindMinDigitSumIndex@8

.model flat
.data

.code

_FindMinDigitSumIndex@8 proc
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx

    mov edi, [ebp + 8]      ; edi = arr
    mov ecx, [ebp + 12]     ; ecx = size

    xor esi, esi            ; esi = ������ i
    mov ebx, 0FFFFFFFFh     ; ebx = ����������� �����
    mov edx, 0              ; edx = ������ � ����������� ������

next_element:
    mov eax, [edi + esi*4]  ; eax = arr[i]
    mov ebx, eax            ; ebx = ����� �����
    xor ecx, ecx            ; ecx = ����� ����

sum_loop:
    xor edx, edx
    mov edx, ebx
    mov ebx, 10
    xor edx, edx
    div ebx                 ; eax / 10, ������� � edx
    add ecx, edx            ; ecx += �����
    mov ebx, eax            ; ebx = ��������� �����
    test eax, eax
    jnz sum_loop

    ; ��������� ����� ���� (ecx) � ����������� (ebx)
    cmp ecx, ebx
    jae skip_update

    ; ���� ����� ����� ������
    mov ebx, ecx
    mov edx, esi            ; ��������� ������ i ��� �����������

skip_update:
    inc esi
    mov eax, [ebp + 12]     ; ������
    cmp esi, eax
    jl next_element

    mov eax, edx            ; ���������� ������

    pop ebx
    pop edi
    pop esi
    pop ebp
    ret 8
_FindMinDigitSumIndex@8 endp

end
