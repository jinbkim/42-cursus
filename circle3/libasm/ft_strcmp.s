;int	ft_strcmp(const char *s1, const char *s2);


 section.text:
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0
	_loop:
		mov al, byte [rdi + rcx]
		mov dl, byte [rsi + rcx]
		cmp al, 0
		jz _al_null
		cmp dl ,0
		jz _dl_null
		cmp al, dl
		ja _plus
		jb _minus
		inc rcx
		jmp _loop
_al_null:
	cmp		dl, byte 0
	jz		_zero
	jmp		_minus
_dl_null:
	cmp al, byte 0
	jz _zero
	jmp _plus
_minus:
	mov rax, -1
	ret
_plus:
	mov rax, 1
	ret
_zero:
	mov rax, 0
	ret