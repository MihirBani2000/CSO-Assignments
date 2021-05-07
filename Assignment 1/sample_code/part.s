.text
.global partition

partition:
    movl $1, %eax #;i
    movl $1, %edx #;j
    movl (%rdi), %r8d #;pivot
.loopback:
    cmp %rsi, %rdx
    je .loopexit
    leaq (%rdi,%rdx,4), %rcx
    movl (%rcx), %r9d #;current
    #;inc %rdx
    cmp %r8d, %r9d
    jge .loopmid
    leaq (%rdi,%rax,4), %r10
    movl (%r10), %r11d
    movl %r11d, (%rcx)
    movl %r9d, (%r10)
    inc %eax
.loopmid:
    inc %edx
    jmp .loopback 
.loopexit:
    dec %eax
    leaq (%rdi,%rax,4), %r10
    movl (%r10), %r9d
    movl %r8d, (%r10)
    movl %r9d, (%rdi)
    ret
