.386

PUBLIC _perestancdecl
PUBLIC _perestanstdcall@8
PUBLIC @perestanfastcall@8

.model flat 
.data
.code 

_perestancdecl proc

 push ebp
 mov ebp, esp

  push ebx
  push esi
  push edi
    
  mov esi, [ebp+8]   
  mov ecx, [ebp+12]   
  shr ecx, 1
  lea edi, [esi + ecx * 4]
xor ebx, ebx      

swap_loop :
mov eax, [esi + ebx * 4] 
mov edx, [edi + ebx * 4] 
mov[esi + ebx * 4], edx 
mov[edi + ebx * 4], eax 
inc ebx           
cmp ebx, ecx      
  jl swap_loop      

  pop edi
  pop esi
  pop ebx
 mov esp, ebp
 pop ebp
 ret

_perestancdecl endp

_perestanstdcall@8 proc

 push ebp
 mov ebp, esp

  push ebx
  push esi
  push edi
    
  mov esi, [ebp+8]   
  mov ecx, [ebp+12]   
  shr ecx, 1
  lea edi, [esi + ecx * 4]
xor ebx, ebx      

swap_loop :
mov eax, [esi + ebx * 4] 
mov edx, [edi + ebx * 4] 
mov[esi + ebx * 4], edx 
mov[edi + ebx * 4], eax 
inc ebx           
cmp ebx, ecx      
  jl swap_loop      

  pop edi
  pop esi
  pop ebx
 mov esp, ebp
 pop ebp
 ret 8

_perestanstdcall@8 endp

@perestanfastcall@8 proc

 push ebp
 mov ebp, esp

  push ebx
  push esi
  push edi
    
  mov esi, edx
  mov ecx, ecx  
  shr ecx, 1
  lea edi, [esi + ecx * 4]
xor ebx, ebx      

swap_loop :
mov eax, [esi + ebx * 4] 
mov edx, [edi + ebx * 4] 
mov[esi + ebx * 4], edx 
mov[edi + ebx * 4], eax 
inc ebx           
cmp ebx, ecx      
  jl swap_loop      

  pop edi
  pop esi
  pop ebx
 mov esp, ebp
 pop ebp
 ret 

@perestanfastcall@8 endp

end