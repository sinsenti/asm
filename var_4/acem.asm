.model flat

public _productDiagonalCdecl
public _productDiagonalStdcall@8
public @productDiagonalFastcall@8

.code


; CDECL соглашение
; int __cdecl productDiagonalCdecl(int* matrix, int size)
_productDiagonalCdecl proc
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx
    
    mov esi, [ebp+8]    ; адрес матрицы
    mov ecx, [ebp+12]   ; размер матрицы
    mov eax, 1          ; начальное значение произведения
    
    xor edi, edi        ; индекс элемента (0..size-1)
    
calc_product_cdecl:
    ; Рассчитываем позицию элемента [i][i]
    mov ebx, edi        ; ebx = i
    imul ebx, ecx       ; ebx = i*size (переход к строке i)
    add ebx, edi        ; ebx = i*size + i (переход к столбцу i)
    imul eax, [esi + ebx*4] ; умножаем на matrix[i][i]
    
    inc edi             ; увеличиваем индекс
    cmp edi, ecx
    jl calc_product_cdecl
    
    pop ebx
    pop edi
    pop esi
    pop ebp
    ret
_productDiagonalCdecl endp

; STDCALL соглашение
; int __stdcall productDiagonalStdcall(int* matrix, int size)
_productDiagonalStdcall@8 proc
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx
    
    mov esi, [ebp+8]    ; адрес матрицы
    mov ecx, [ebp+12]   ; размер матрицы
    mov eax, 1
    
    xor edi, edi
    
calc_product_stdcall:
    mov ebx, edi
    imul ebx, ecx
    add ebx, edi
    imul eax, [esi + ebx*4]
    
    inc edi
    cmp edi, ecx
    jl calc_product_stdcall
    
    pop ebx
    pop edi
    pop esi
    pop ebp
    ret 8
_productDiagonalStdcall@8 endp

; FASTCALL соглашение
; int __fastcall productDiagonalFastcall(int size, int* matrix)
@productDiagonalFastcall@8 proc
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx
    
    mov esi, edx        ; адрес матрицы
    mov ecx, ecx        ; размер матрицы
    mov eax, 1
    
    xor edi, edi
    
calc_product_fastcall:
    mov ebx, edi
    imul ebx, ecx
    add ebx, edi
    imul eax, [esi + ebx*4]
    
    inc edi
    cmp edi, ecx
    jl calc_product_fastcall
    
    pop ebx
    pop edi
    pop esi
    pop ebp
    ret
@productDiagonalFastcall@8 endp

end
