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
	L1 SDWORD 10
	L2 SDWORD 15

.data
	buffer BYTE 256 dup(0)
	maina SDWORD 0
	mainb SDWORD 0
	mainc SDWORD 0

.code

main PROC
	push L1
	pop maina
	push L2
	pop mainb
	push maina
	push mainb
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop mainc
	push mainc
	call OutputInt
	call ExitProcess
main ENDP
end main