bits 64

global ft_atoi_base
extern ft_strlen

ft_atoi_base:
	push	r12
	push	r13
	push	r14
	push	r15
	cmp		rdi, 0
	je		error
	cmp		rsi, 0
	je		error
	mov		r15, rdi
	mov		rdi, rsi
	call	ft_strlen
	cmp		rax, 0
	je		error
	cmp		rax, 1
	je		error
	mov		rsi, rdi
	mov		rdi, r15
	mov		r14, rax

mov		rcx, -1
base_loop:
	inc		rcx
	cmp		byte [rsi + rcx], 0
	je		convert
	cmp		byte [rsi + rcx], '+'
	je		error
	cmp		byte [rsi + rcx], '-'
	je		error
	cmp		byte [rsi + rcx], ' '
	jle		error
	cmp		byte [rsi + rcx], 127
	jge		error

mov		rdx, rcx
base_inner_loop:
	inc		rdx
	cmp		byte [rsi + rdx], 0
	je		base_loop
	movzx	r11, byte [rsi + rdx]
	movzx	r12, byte [rsi + rcx]
	cmp		r11, r12
	je		error
	jmp		base_inner_loop
	
convert:
	mov		r13, 1
	mov		rax, 0
skip:
	cmp		byte [rdi], 32
	je		skip_space
	cmp		byte [rdi], 9
	je		skip_space
	cmp		byte [rdi], 10
	je		skip_space
	cmp		byte [rdi], 11
	je		skip_space
	cmp		byte [rdi], 12
	je		skip_space
	cmp		byte [rdi], 13
	je		skip_space
	jmp		skip_sign

skip_space:
	inc		rdi
	jmp		skip

skip_sign:
	cmp		byte [rdi], '+'
	je		skip_sign_plus
	cmp		byte [rdi], '-'
	je		skip_sign_minus
	jmp		get_nb

skip_sign_plus:
	inc		rdi
	jmp		skip_sign

skip_sign_minus:
	inc		rdi
	neg		r13
	jmp		skip_sign

get_nb:
	mov		rax, 0

get_nb_loop:
	cmp		byte [rdi], 0
	je		return
	movzx	r11, byte [rdi]
	jmp		get_index

add_index:
	imul	rax, r14
	add		rax, rcx
	inc		rdi
	jmp		get_nb_loop

get_index:
	mov		rcx, 0
get_index_loop:
	cmp		byte [rsi + rcx], 0
	je		exit
	movzx	r12, byte [rsi + rcx]
	cmp		r11, r12
	je		add_index
	inc		rcx
	jmp		get_index_loop

error:
	mov		rax, 0 
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	ret

exit:
	imul	rax, r13
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	ret

return:
	imul	rax, r13
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	ret