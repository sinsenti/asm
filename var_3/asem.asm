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

    xor esi, esi            ; esi = индекс i
    mov ebx, 0FFFFFFFFh     ; ebx = минимальная сумма
    mov edx, 0              ; edx = индекс с минимальной суммой

next_element:
    mov eax, [edi + esi*4]  ; eax = arr[i]
    mov ebx, eax            ; ebx = копия числа
    xor ecx, ecx            ; ecx = сумма цифр

sum_loop:
    xor edx, edx
    mov edx, ebx
    mov ebx, 10
    xor edx, edx
    div ebx                 ; eax / 10, остаток в edx
    add ecx, edx            ; ecx += цифра
    mov ebx, eax            ; ebx = следующее число
    test eax, eax
    jnz sum_loop

    ; сравнение суммы цифр (ecx) с минимальной (ebx)
    cmp ecx, ebx
    jae skip_update

    ; если новая сумма меньше
    mov ebx, ecx
    mov edx, esi            ; сохранить индекс i как минимальный

skip_update:
    inc esi
    mov eax, [ebp + 12]     ; размер
    cmp esi, eax
    jl next_element

    mov eax, edx            ; возвращаем индекс

    pop ebx
    pop edi
    pop esi
    pop ebp
    ret 8
_FindMinDigitSumIndex@8 endp

end
