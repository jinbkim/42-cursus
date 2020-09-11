;char	*ft_strcpy(char *dst, const char *src);


section.text:
	global _ft_strcpy

_ft_strcpy:
	push	rbx
	push	rcx
	mov		rax, rdi
	mov		rbx, rsi
	mov		rcx, -1
	_loop:
		inc		rcx
		mov		dl, byte [rbx + rcx]
		mov		byte [rax + rcx], dl
		cmp		byte [rbx + rcx], 0
		jnz		_loop
		pop		rcx
		pop		rbx
		ret