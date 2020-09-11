;char *		ft_strdup(const char *s1)

section.text:
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_strcpy

_ft_strdup:
	call	_ft_strlen
	inc		rax
	push	rdi
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	jz		_error
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy
	ret

_error:
	pop		rdi;
	ret