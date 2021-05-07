.text
.global four_tower_of_hanoi

four_tower_of_hanoi:
    # n is in %rdi
    
    # function start - keeping track of the stack pointer
    pushq %rbp       
    movq %rsp, %rbp

    pushq %r12      # pushing into stack before using
    pushq %r13      # pushing into stack before using

    call toh4       # calling the function
    
    popq %r13       # popping out from stack
    popq %r12       # popping out from stack
    jmp .return
    
toh4:
    # the function for caculating the number of moves in 4 tower of Hanoi problem
    # n in %rdi
    # loop counter i in %r8
    # count in %r9
    # temp in %rcx
    # temp1 in %12
    # temp2 in %13

    # function start - keeping track of the stack pointer
    pushq %rbp       
    movq %rsp, %rbp

    # base condition of recursion
    cmpq $1, %rdi    # (n==1)
    je .return1

    movq $-1, %r8    # i = -1
    .my_loop:
        inc %r8             # i++
        movq %r8, %r12      # temp1 = i
        inc %r12            # temp1 = i+1
        imulq %r8, %r12     # temp1 = i*(i+1)
        movq %rdi, %r13     # temp2 = n
        salq $1, %r13       # temp2 = n*2
        cmpq %r12, %r13     # if (i * (i + 1)) <= (2 * n)
        jge .my_loop 

    dec %r8             # i--
    movq $0, %r9        # count = 0
    
    # for_calling_4toh:
    # count += 2 * (four_tower_of_hanoi(n - i));
    pushq %r9           # pushing count
    pushq %r8           # pushing i
    pushq %rdi          # pushing n
    
    subq %r8, %rdi      # %rdi = n-i
    call toh4           # call the function recursively
    movq %rax, %rcx     # storing the return value in %rcx
    salq $1, %rcx       # %rcx = %rcx << 1

    popq %rdi          # popping n
    popq %r8           # popping i
    popq %r9           # popping count
    
    addq %rcx, %r9      # count += 2*toh4(n-i)

    # for_calling_3toh:
    # count += tower_of_hanoi(i);
    pushq %r9           # pushing count
    pushq %r8           # pushing i
    pushq %rdi          # pushing n
    
    movq %r8, %rdi      # %rdi = i
    call toh3           # call the function for 3 towers
    movq %rax, %rcx     # storing the return value in %rcx
    
    popq %rdi          # popping n
    popq %r8           # popping i
    popq %r9           # popping count
    
    addq %rcx, %r9      # count += toh3(i)
    
.return_final_ans:   # return count
    movq %r9, %rax
    jmp .return

.return1:           # return 1
    movq $1, %rax
    jmp .return

.return:
    movq %rbp, %rsp     # restoring the stack pointer, from during the function call
    popq %rbp           # restoring the value of %rbp
    ret

# function for 3 tower of hanoi
toh3:
    # the function for caculating the number of moves in 3 tower of Hanoi problem
    # n in %rdi
    # count in %r11
    # temp in %rcx

    # function start - keeping track of the stack pointer
    pushq %rbp       
    movq %rsp, %rbp

    # base condition of recursion
    cmpq $1, %rdi    # (n==1)
    je .return1

    movq $1, %r11    # count = 1;
    # for_calling_toh3:
    # count += 2*tower_of_hanoi(i);
    pushq %r11          # pushing count
    pushq %rdi          # pushing n
    
    dec %rdi            # n = n-1
    call toh3           # call the function recursively
    movq %rax, %rcx     # storing the return value in %rcx
    salq $1, %rcx       # %rcx = %rcx << 1

    popq %rdi           # popping n
    popq %r11           # popping count
    
    addq %rcx, %r11     # count += 2*toh3(i)    

    movq %r11, %rax     # %rax = count
    
    # for returing back
    movq %rbp, %rsp     # restoring the stack pointer, from during the function call
    popq %rbp           # restoring the value of %rbp
    ret
