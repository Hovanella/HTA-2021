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

.stack 4096

.const

.data
	buffer BYTE 256 dup(0)
	maina SDWORD 0

.code

main PROC
	call destiny
	push eax
	pop maina
	push maina
	call OutputInt
	call ExitProcess
main ENDP
end main