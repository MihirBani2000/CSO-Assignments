.text
.global func

func:
    # n is in %rdi
    # counter = 0 in %rax
    # temp in %r10

    movq $0, %rax       # counter = 0
    movq %rdi, %r10     # temp = n

.mainloop:
    cmpq $0, %rdi    # checking n==0 
    je .loopexit
    movq %rdi, %r10  # temp = n
    andq $1, %r10    # temp = temp&1
    addq %r10, %rax  # counter += temp
    shrq $1, %rdi    # n = n>>1, logical shift
    jmp .mainloop

.loopexit:
    andq $1, %rax    # returns (counter & 1)
    ret
