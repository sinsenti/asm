.386
PUBLIC _FindMostFrequent1@8
PUBLIC _FindMostFrequent2
PUBLIC @FindMostFrequent3@8

.model flat

.code

_FindMostFrequent1@8 proc
    push esi
    push edi
    mov esi, [esp + 12]
    mov edi, [esp + 16]
    push ebp
    push ebx
    
    xor ebx, ebx
    mov ecx, -1
    mov edx, 1
    
outer_loop:
    mov eax, [esi + ebx*4]
    push ebx
    mov ebx, 1
    
    mov ebp, [esp]
    inc ebp
    
inner_loop:
    cmp ebp, edi
    jge end_inner_loop
    
    cmp eax, [esi + ebp*4]
    jne not_equal
    inc ebx
    
not_equal:
    inc ebp
    jmp inner_loop
    
end_inner_loop:
    cmp ebx, edx
    jle not_new_max
    
    mov edx, ebx
    mov ecx, eax
    
not_new_max:
    pop ebx
    inc ebx
    cmp ebx, edi
    jl outer_loop

    mov eax, ecx

    pop ebx
    pop ebp
    pop edi
    pop esi
    ret 8
_FindMostFrequent1@8 endp

_FindMostFrequent2 proc
    push esi
    push edi
    mov esi, [esp + 12]
    mov edi, [esp + 16]
    push ebp
    push ebx
    
    xor ebx, ebx
    mov ecx, -1
    mov edx, 1
    
outer_loop:
    mov eax, [esi + ebx*4]
    push ebx
    mov ebx, 1
    
    mov ebp, [esp]
    inc ebp
    
inner_loop:
    cmp ebp, edi
    jge end_inner_loop
    
    cmp eax, [esi + ebp*4]
    jne not_equal
    inc ebx
    
not_equal:
    inc ebp
    jmp inner_loop
    
end_inner_loop:
    cmp ebx, edx
    jle not_new_max
    
    mov edx, ebx
    mov ecx, eax
    
not_new_max:
    pop ebx
    inc ebx
    cmp ebx, edi
    jl outer_loop

    mov eax, ecx

    pop ebx
    pop ebp
    pop edi
    pop esi
    ret
_FindMostFrequent2 endp

@FindMostFrequent3@8 proc
    push ebp
    push ebx
    push esi
    push edi
    
    mov esi, ecx
    mov edi, edx
    
    xor ebx, ebx
    mov ecx, -1
    mov edx, 1
    
outer_loop:
    mov eax, [esi + ebx*4]
    push ebx
    mov ebx, 1
    
    mov ebp, [esp]
    inc ebp
    
inner_loop:
    cmp ebp, edi
    jge end_inner_loop
    
    cmp eax, [esi + ebp*4]
    jne not_equal
    inc ebx
    
not_equal:
    inc ebp
    jmp inner_loop
    
end_inner_loop:
    cmp ebx, edx
    jle not_new_max
    
    mov edx, ebx
    mov ecx, eax
    
not_new_max:
    pop ebx
    inc ebx
    cmp ebx, edi
    jl outer_loop

    mov eax, ecx

    pop edi
    pop esi
    pop ebx
    pop ebp
    ret
@FindMostFrequent3@8 endp

end