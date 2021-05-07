.text
.global find_ans

find_ans:
    # n is in %rdi
    # m is in %rsi
    # sum in %rcx
    # i in %r8
    # j in %r9

    movq $0, %rcx       # sum = 0
    movq $1, %r8        # i = 1

.outerloop:
    inc %r8             # i++
    cmpq %r8, %rdi      # check n - i > 0  
    je .mainexit

    movq $2, %r9            # j = 2
    .innerloop:
        movq %r9, %r10      # r10 = j
        imulq %r10, %r10    # j*j
        cmpq %r10, %r8      # check i - j*j >= 0 
        js .if_prime        # jmp if negative

        # main work happening
        # check if (i%j==0)
        movq %r8, %rax      # stores i in %rax 
        cqto
        idivq %r9           # i/j
        cmpq $0, %rdx        # if i%j==0
        je .outerloop       # then jmp .outerloop

        inc %r9             # j++
        jmp .innerloop

    .if_prime:
        # sum = (sum + i) % m
        addq %r8, %rcx      # sum += i
        movq %rcx, %rax     # moving sum to %rax
        cqto                
        idivq %rsi          # sum/i
        movq %rdx, %rcx     # sum = sum % i

    jmp .outerloop

.mainexit:
    movq %rcx, %rax         # return sum
    ret
