.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/StaticLibrary.lib
ExitProcess PROTO :DWORD

EXTRN BREAKL: proc
EXTRN OutputInt: proc
EXTRN OutputStr: proc
EXTRN OutputIntLn: proc
EXTRN OutputStrLn: proc
EXTRN ShowChar: proc
EXTRN ShowCharLine: proc
EXTRN destiny: proc
EXTRN findSymb: proc

.stack 4096

.const
	L1 BYTE "funcion 1 works", 0
	L2 BYTE "void 1 works", 0
	L3 SDWORD 12
	L4 SDWORD -11
	L5 SDWORD 16
	L6 SDWORD 1
	L7 SDWORD 2
	L8 SDWORD 0
	L9 SDWORD 4
	L10 BYTE "Destiny is ", 0
	L11 BYTE "abc", 0
	L12 BYTE "b", 0
	L13 BYTE "Position + 1 - ", 0
	L14 BYTE "condition true", 0
	L15 BYTE "condition false", 0
	L16 SDWORD 10

.data
	buffer BYTE 256 dup(0)
	func1res SDWORD 0
	MAJORnumber SDWORD 0
	MAJORnumber2 SDWORD 0
	MAJORnumber3 SDWORD 0
	MAJORnumber4 SDWORD 0
	MAJORdest SDWORD 0
	MAJORstr DWORD ?
	MAJORc DWORD ?
	MAJORpos SDWORD 0
	MAJORi SDWORD 0

.code

func1 PROC func1a : SDWORD, func1b : SDWORD
	push offset L1
	call OutputStrLn
	push func1a
	push func1b
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop func1res
	push func1res
	jmp local0
local0:
	pop eax
	ret
func1 ENDP

proc1 PROC 
	push offset L2
	call OutputStrLn
	pop eax
	ret
proc1 ENDP

main PROC
	push L3
	pop MAJORnumber
	push L4
	pop MAJORnumber2
	push L5
	pop MAJORnumber3
	push L6
	push L7
	pop edx
	pop edx
	push L7
	push L6
	call func1
	push eax
	push MAJORnumber
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push MAJORnumber2
	pop ebx
	pop eax
	cdq
	idiv ebx
	push eax
	pop MAJORnumber4
	push L8
	push L9
	pop edx
	pop edx
	push L9
	push L8
	call destiny
	push eax
	push L7
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop MAJORdest
	push offset L10
	call OutputStr
	push MAJORdest
	call OutputIntLn
	push offset L11
	pop MAJORstr
	push offset L12
	pop MAJORc
	push MAJORstr
	push MAJORc
	pop edx
	pop edx
	push MAJORc
	push MAJORstr
	call findSymb
	push eax
	push L6
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop MAJORpos
	push offset L13
	call OutputStr
	push MAJORpos
	call OutputIntLn
	push MAJORnumber4
	call OutputIntLn
	call proc1
	mov eax, MAJORnumber
	cmp eax, MAJORnumber2
	jz m0
	jnz m1
	je m1
m0:
	push offset L14
	call OutputStrLn
	jmp e0
m1:
	push offset L15
	call OutputStrLn
e0:
	push L6
	pop MAJORi
	mov eax, MAJORi
	cmp eax, L16
	jl cycle0
	jmp cyclenext0
cycle0:
	push MAJORi
	push L6
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop MAJORi
	push MAJORi
	call OutputIntLn
	mov eax, MAJORi
	cmp eax, L16
	jl cycle0
cyclenext0:
	call ExitProcess
main ENDP
end main