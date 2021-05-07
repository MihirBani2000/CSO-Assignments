.text
.global nqueen1

nqueen1:
# board is in %rdi -> %r13
# curr_col is in %rsi
# n in %rdx -> %r12
	pushq %r12   # pushing it to the stack before using
	pushq %r13   # pushing it to the stack before using

    call nqueen  # calling the function
    .exit: 
    	popq %r13
    	popq %r12
    	ret 

nqueen:
    # loop counter - i in %r8
    # temp in %rcx

    # function start - keeping track of the stack pointer
    pushq %rbp       
    movq %rsp, %rbp

    # base condition of recursion
    cmpq %rdx, %rsi    # (col >= n)
    jge .return1

    movq $-1, %r8    # i = -1
	.mainloop:
	    inc %r8 # i++
	    # loop condition
	    cmpq %rdx, %r8   # (i >= n)
	    jge .return0
	    
	    # isSafe(board (%r13), i(%r11), col(%r10), n(%r12))
	    # isSafe(board (%rdi), i(%r11), col(%r10), n(%rdx))
	    movq %rdi, %r13     # %r13 = %rdi
	    movq %r8, %r11      # %r11 (row) = i
	    movq %rsi, %r10     # %r10 (col) = col
	    movq %rdx, %r12     # %r12 = %rdx
	    
	    jmp .isSafe         # returns 1 in %r9 if safe
	    .backFromSafe:
	    cmpq $1, %r9
	    jne .mainloop       # continue the loop if not safe


	    movq %r12, %rcx             # temp = n
	    imulq %r8, %rcx             # temp = i*n
	    addq %rsi, %rcx             # temp = i*n + col
	    movq $1, (%r13, %rcx, 8)    # board[i][col] = 1

	    pushq %rsi          # saving the current col
	    pushq %r8           # saving the loop counter i
	    inc %rsi            # col++
	    
	    call nqueen     # arguments(%rdi(board), %rsi(col+1), %r12(n))
	    
	    popq %r8        # restoring the value of i from stack
	    popq %rsi       # restoring the value of col from stack

	    cmpq $1, %rax   # check if nqueen returned 1
	    je .return1

	    movq %r12, %rcx             # temp = n
	    imulq %r8, %rcx             # temp = i*n
	    addq %rsi, %rcx             # temp = i*n + col
	    movq $0, (%r13, %rcx, 8)    # board[i][col] = 0

	    jmp .mainloop       # continue the loop


.return0:   # return 0
    movq $0, %rax
    jmp .return

.return1:   # return 1
    movq $1, %rax
    jmp .return

.return:
    movq %rbp, %rsp     # restoring the stack pointer, from during the function call
    popq %rbp           # restoring the value of %rbp
    ret

.isSafe: # (board, row, col, n)
    # board in %r13
    # row in %r11
    # col in %r10
    # n in %r12
    # flag in %r9
    # i in %r14
    # j in %r15
    # temp in %rcx

    pushq %r14
    pushq %r15

    movq $1, %r9       # flag = 1
    # jmp .retSafe

    # upper left diagonal check
    movq %r11, %r14     # i = row
    movq %r10, %r15     # j = col
    
    .loop1: 
        # loop condition
        cmpq $0, %r14       # if (i<0)
        jl .loop2init       #   .loop2 
        cmpq $0, %r15       # if (j<0)
        jl .loop2init       #   .loop2

        # board checking
        movq %r12, %rcx             # temp = n
        imulq %r14, %rcx            # temp = i*n
        addq %r15, %rcx             # temp = i*n + j
        cmpq $1, (%r13, %rcx, 8)    # *(board + (i*n + j)*8) == 1
        je .retNotSafe

        dec %r14    # i--
        dec %r15    # j--
        jmp .loop1

    .loop2init:
    # check in the same row
    movq $0, %r14     # i = 0
    movq $0, %r15     # j = 0

    .loop2: 
        # loop condition
        cmpq %r10, %r14     # if (i >= col)
        jge .loop3init      #   .loop2

        # board checking
        movq %r12, %rcx             # temp = n
        imulq %r11, %rcx            # temp = row*n
        addq %r14, %rcx             # temp = row*n + i
        cmpq $1, (%r13, %rcx, 8)    # *(board + (row*n + i)*8) == 1
        je .retNotSafe

        inc %r14    # i++
        jmp .loop2

    .loop3init:
    # lower left diagonal check
    movq %r11, %r14     # i = row
    movq %r10, %r15     # j = col

    .loop3: 
        # loop condition
        cmpq %r12, %r14      # if ( i >= n )
        jge .retSafe         #   .retSafe 
        cmpq $0, %r15        # if (j<0)
        jl .retSafe          #   .retSafe

        # board checking
        movq %r12, %rcx             # temp = n
        imulq %r14, %rcx            # temp = i*n
        addq %r15, %rcx             # temp = i*n + j
        cmpq $1, (%r13, %rcx, 8)    # *(board + (i*n + j)*8) == 1
        je .retNotSafe

        inc %r14    # i++
        dec %r15    # j--
        jmp .loop3

    .retNotSafe:
    movq $0, %r9   # flag = 0

    .retSafe:
    popq %r15
    popq %r14
    jmp .backFromSafe
    # the flag is stored in %r9
